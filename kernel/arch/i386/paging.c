#include <kernel/link_var.h>
#include <kernel/paging.h>

void paging_init() {
  paging_directories = (struct paging_dir_desc*) _DIRECTORY_TABLE;
  paging_pages = (struct paging_page_desc*) _PAGE_TABLE;
}
