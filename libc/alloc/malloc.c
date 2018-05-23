#include <alloc.h>
#include <stdint.h>
#include <stdbool.h>
#include <syscall.h>

/* Block layouts
   Full
      [  head1  | data ]
        4 Bytes
   Free (size >= 16 bytes)
      [  head2  | ptr_to_next | free | ptr_to_prev |  head2  ]
        4 bytes     4 Bytes              4 Bytes     4 Bytes
   Free (size = 12 bytes)
      [ head3a  | ptr_to_next | head3b  ]
        4 Bytes     4 Bytes     4 Bytes

   Headers description
          |    31-2     |   1   |               0
   head1  | block size  | set   | prev block status (set if full)
   head2  | block size  | unset | set
   head3a | unused      | unset | unset
   head3b | ptr_to_prev | unset | unset
 */

#define max(a,b) \
  (((a)>(b))?(a):(b))

#define get_addr(free_addr) \
  ((uint32_t*) ((free_addr) << 2))

#define shrink_addr(free_addr) \
  (((uint32_t) (free_addr)) >> 2)

#define pages_needed(size) \
  (((uint32_t) size) - ((uint32_t) remaining))

#define minsize 8

struct head_t {
  bool bit0 : 1;
  bool status : 1;
  uint32_t size_or_ptr : 30;
};

struct HEAP_START_t {
  bool full : 1;
  bool init : 1;
  uint32_t fst_free : 30;
};

void* init_heap(struct HEAP_START_t* hpstart) {
  hpstart->init=1;
  // Init of first free block (Free, blocksize >= 16)
  // Header init
  struct head_t* fst_free = (struct head_t*) get_addr(hpstart->fst_free);
  uint32_t* data_addr = (uint32_t*) fst_free + 1;
  fst_free->size_or_ptr = (uint32_t*) HEAP_END - data_addr;
  fst_free->status = 0;
  fst_free->bit0 = 1;
  // Prev free block init
  *data_addr = (uint32_t) data_addr;
  // Header copy init
  uint32_t* header_copy = HEAP_END - 1;
  *header_copy = *((uint32_t*) fst_free);
  // Next free block init
  *(header_copy - 1) = (uint32_t) data_addr;
  return NULL;
};

void* allocate_h2_large(struct head_t* header, size_t size, size_t blocksize,
    bool last_free) {
  // First we initialise the full block status
  header->status = 1;
  header->bit0 = 1;
  // We set the new free block
  struct head_t* new_free =
    (struct head_t*) (((uint8_t*) header) + size + 4);
  new_free->status = 0;
  // We determine wether free header is a head2 or head3
  struct head_t* end_header = NULL;
  if (blocksize >= size+16) {
    // head2
    new_free->bit0 = 1; // bit0 tells that it is a head2
    new_free->size_or_ptr = ((blocksize-size) >> 2) - 1; // We indicate the size
      // of the new free block (header space has to be taken into account)
    *(((uint32_t*) new_free) + 1) = *(((uint32_t*) header) + 1 ); // We set the
      // next free block
    end_header = // We move to the end copy of the header
      (struct head_t*) (((uint8_t*) header) + blocksize);
    *end_header = *header; // The end header is a copy in head2
    if (last_free) { // The current block is the last free block, we have to
      // treat it differently
      *(((uint32_t*) end_header) - 1) = (uint32_t) new_free;
    };
  } else {
    // head3
    new_free->bit0 = 0;
    // Now we move to the end header
    end_header = (struct head_t*) (((uint8_t*) header) + blocksize);
    // Little shortcut : in head3b status=bit0=0
    if (last_free) {
      *((uint32_t*) end_header) = (uint32_t) new_free;
    } else {
      *((uint32_t*) end_header) = *(((uint32_t*) end_header) - 1);
    };
    if (last_free) {
      *(((uint32_t*) new_free) + 1) = (uint32_t) new_free;
    } else {
      *(((uint32_t*) new_free) + 1) = *(((uint32_t*) header) + 1);
    };
  };
  // We have to complete the initialisation of 'header'
  header->size_or_ptr = (uint32_t) size >> 2;
  // All is done
  return (void*) (((uint32_t*) header) + 1);
};

void* allocate_h2(struct head_t* header, size_t size, size_t blocksize,
    bool last_free, struct HEAP_START_t* hpstart) {
  if (last_free) { // We have to indicate that the page is full
    hpstart->full = 1;
  } else { // We have to update nearby free blocks
    struct head_t* next_free =
      (struct head_t*)  (*(((uint32_t*) header) + 1));
    struct head_t* prev_free =
      (struct head_t*)  (*((uint32_t*) (((uint8_t*) header) + blocksize)));
    *(((uint32_t*) prev_free) + 1) = (uint32_t) next_free;
    if (next_free->bit0) {
      *((uint32_t*) (((uint8_t*) header) + blocksize - 1)) =
        (uint32_t) prev_free;
    } else {
      *(((uint32_t*) header) + 2) = (uint32_t) prev_free;
    }
  };
  // We initialise the full block
  header->status = 1;
  header->bit0 = 1;
  header->size_or_ptr = (uint32_t) size >> 2;
  // All is done
  return (void*) (((uint32_t*) header) + 1);
};

void* allocate_h3(struct head_t* header, bool last_free,
    struct HEAP_START_t* hpstart) {
  if (last_free) { // We have to indicate that the page is full
    hpstart->full = 1;
  } else { // We have to update nearby free blocks
    struct head_t* next_free =
      (struct head_t*)  (*(((uint32_t*) header) + 1));
    struct head_t* prev_free =
      (struct head_t*)  (*(((uint32_t*) header) + 2));
    *(((uint32_t*) prev_free) + 1) = (uint32_t) next_free;
    if (next_free->bit0) {
      *(((uint32_t*) header) + 2) =
        (uint32_t) prev_free;
    } else {
      *(((uint32_t*) header) + 2) = (uint32_t) prev_free;
    }
  };
  // We initialise the full block
  header->status = 1;
  header->bit0 = 1;
  header->size_or_ptr = 3;
  // All is done
  return (void*) (((uint32_t*) header) + 1);
};

void* malloc(size_t size) {
  if (!size) {
    return NULL;
  } else {
    size = max(size,minsize);
    // Then we have to make sure the size is a multiple of 4 (it will be easier)
    int size_mod_4 = size%4;
    if (size_mod_4) {
      size = size - size_mod_4 + 4;
    };
    struct HEAP_START_t* hpstart = (struct HEAP_START_t*) HEAP_START;
    // First, we check whether the memory is initialised
    if (! hpstart->init) {init_heap(hpstart);};
    // We can look for some place
    // We check if there is still room for data
    if (hpstart->full) {
      // TODO Request new page (according to the size)
      // Initialise this as a new block
    };
    // There is room for data, we check for a large enough free block
    // First we remember where the first free block is
    uint32_t* fst_free_block = get_addr(hpstart->fst_free);
    // Then we go to that first free block
    uint32_t* curr_block = fst_free_block;
    // Preparing for the loop
    bool* error = 0;
    bool last_free = (*(curr_block + 1) == (uint32_t) curr_block);
    // Then we loop
    while (! error) {
      uint32_t* next = (uint32_t*) *(curr_block + 1);
      // We check whether the current block is large enough
      // We determine of which type the header is
      struct head_t* header = (struct head_t*) curr_block;
      if (header->bit0) {
        // The header is a head2 header
        // We can check whether the size is ok
        uint32_t blocksize = (header->size_or_ptr) << 2;
        if (blocksize >= size+minsize+4) {
          // Size is largely ok
          return (allocate_h2_large(header,size,blocksize,last_free));
        } else if (blocksize >= size) {
          // Size is ok
          return (allocate_h2(header,size,blocksize,last_free,hpstart));
        } else {
          // Size is not enough, we have to move on to the next block
          if (next == (uint32_t*) (get_addr(hpstart->fst_free))) {
            // We have to request another page and adapt the last block
            // Then we can just pretend that new big last block is the block
            // we just arrived to. If there was an error, we set 'error' to 1
            // And we manage it now #TODO
          } else {
            // We just go to the next block
            curr_block = next;
          }
        }
      } else {
        // The header is a head3 header
        // We can check whether the size is ok
        if (minsize == size) {
          // Size is ok
          return (allocate_h3(header,last_free,hpstart));
        } else {
          // Size is not enough, we have to move on to the next block
          if (next == (uint32_t*) (get_addr (hpstart->fst_free))) {
            // We have to request another page and adapt the last block
            // Then we can just pretend that new big last block is the block
            // we just arrived to. If there was an error, we set 'error' to 1
            // And we manage it now #TODO
          } else {
            // We just go to the next block
            curr_block = next;
          }
        }
      }
    }
    // Error management
  };
  return NULL;
};
