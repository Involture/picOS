#include <kernel/link_var.h>
#include <kernel/paging.h>

void paging_init() {
  struct page_entry* paging_directories = (struct page_entry*) _DIRECTORY_TABLE;
  struct page_entry* paging_pages = (struct page_entry*) _PAGE_TABLE;
}
