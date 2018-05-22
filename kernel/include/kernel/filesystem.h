#ifndef _KERNEL_FILESYSTEM
#define _KERNEL_FILESYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
// #include <stddef.h>
#include <stdbool.h>

#define FILESYSTEM_INODE_BLOCKS_MAX_NB 8
#define FILESYSTEM_ELEMENTS_MAX_NB 65536

// 16 + 16 + 1 + 16 + 32 + 32 + 8 = 121 bits used for 1 inode
struct inode {
	uint16_t i_id;
	char* i_filename;
	uint16_t i_parent_id;
	bool i_is_a_dir;
	uint16_t i_nb_elements;
	uint16_t i_size;
	// [addr_a ; addr_b[
	uint8_t* i_addr_a;
	uint8_t* i_addr_b; 
};


// init0
void filesystem_init(void);

// finds id from filename : if = 0 error
uint16_t filesystem_find_id_from_fn(char*);
// finds filename from id : if NULL error
char* filesystem_find_fn_from_id(uint16_t);


// returns the id of the inode corresponding to the created file : if 0 error
uint16_t filesystem_new_file(char*, bool);
// returns the id of the inode corresponding to the deleted file : if 0 error
uint16_t filesystem_delete_file(uint16_t);
void filesystem_clear_file(uint16_t);

/* id = f : x \mapsto x, with some side effects */
// returns the id of the inode corresponding to the "opened" file : if 0 error
uint16_t filesystem_open_file(uint16_t);
// returns the id of the inode corresponding to the "closed" file : if 0 error 
uint16_t filesystem_close_file(uint16_t);

/* buffer = malloc */
/* symmetry due to the existence of pipes */
// takes inode id, pointer to a buffer, and the number of bits to read
// returns the number of bits that have been read : if < 0 error
int16_t filesystem_read_file(uint16_t, void*, uint16_t);
// takes inode id, pointer to a buffer, and the number of bits to write
// returns the number of bits that have been wrote : if < 0 error
int16_t filesystem_write_file(uint16_t, void*, uint16_t);

// functions to modify the content of the current directory seen as a file, containing informations about the current directory

// particular cases of the two previous functions
void filesystem_write_file_byte(uint16_t, uint8_t, bool, uint32_t);
uint8_t filesystem_read_file_byte(uint16_t, uint32_t);

#endif
