#ifndef _LINK_VAR_H
#define _LINK_VAR_H

#include <stdint.h>

extern int LOADER_SIZE;
extern int LOADER_PAGE_NUMBER;
extern int LOADER_DIR_NUMBER;

extern int LOWER_PHYSICAL_BASE;
extern int LOWER_PHYSICAL_PAGE;
extern int LOWER_PHYSICAL_DIR;

extern int UPPER_VIRTUAL_BASE;
extern int UPPER_VIRTUAL_PAGE;
extern int UPPER_VIRTUAL_DIR;

extern int UPPER_PHYSICAL_BASE;
extern int UPPER_PHYSICAL_PAGE;
extern int UPPER_PHYSICAL_DIR;

extern int KERNEL_STACK_TOP;

extern int UPPER_SIZE;
extern int UPPER_PAGE_NUMBER;
extern int UPPER_DIR_NUMBER;

extern int LOWER_SIZE;
extern int LOWER_PAGE_NUMBER;
extern int LOWER_DIR_NUMBER;

extern int UPPER_OFFSET;
extern int UPPER_PAGE_OFFSET;
extern int UPPER_PAGE_OFFSET;

extern int TOTAL_PAGE_NUMBER;
extern int TOTAL_DIR_NUMBER;

extern int DIRECTORY_TABLE;
extern int PAGE_TABLE;
extern int PHYSICAL_DIRECTORY_TABLE;
extern int PHYSICAL_PAGE_TABLE;

#define get_link_var(x) ((uint32_t) &x)

#define _LOADER_SIZE          get_link_var(LOADER_SIZE)
#define _LOADER_PAGE_NUMBER   get_link_var(LOADER_PAGE_NUMBER)
#define _LOADER_DIR_NUMBER    get_link_var(LOADER_DIR_NUMBER)

#define _LOWER_PHYSICAL_BASE  get_link_var(LOWER_PHYSICAL_BASE)
#define _LOWER_PHYSICAL_PAGE  get_link_var(LOWER_PHYSICAL_PAGE)
#define _LOWER_PHYSICAL_DIR   get_link_var(LOWER_PHYSICAL_DIR)

#define _UPPER_VIRTUAL_BASE   get_link_var(UPPER_VIRTUAL_BASE)
#define _UPPER_VIRTUAL_PAGE   get_link_var(UPPER_VIRTUAL_PAGE)
#define _UPPER_VIRTUAL_DIR    get_link_var(UPPER_VIRTUAL_DIR)

#define _UPPER_PHYSICAL_BASE  get_link_var(UPPER_PHYSICAL_BASE)
#define _UPPER_PHYSICAL_PAGE  get_link_var(UPPER_PHYSICAL_PAGE)
#define _UPPER_PHYSICAL_DIR   get_link_var(UPPER_PHYSICAL_DIR)

#define _KERNEL_STACK_TOP     get_link_var(KERNEL_STACK_TOP)

#define _UPPER_SIZE           get_link_var(UPPER_SIZE)
#define _UPPER_PAGE_NUMBER    get_link_var(UPPER_PAGE_NUMBER)
#define _UPPER_DIR_NUMBER     get_link_var(UPPER_DIR_NUMBER)

#define _LOWER_SIZE           get_link_var(LOWER_SIZE)
#define _LOWER_PAGE_NUMBER    get_link_var(LOWER_PAGE_NUMBER)
#define _LOWER_DIR_NUMBER     get_link_var(LOWER_DIR_NUMBER)

#define _UPPER_OFFSET         get_link_var(UPPER_OFFSET)
#define _UPPER_PAGE_OFFSET    get_link_var(UPPER_PAGE_OFFSET)
#define _UPPER_DIR_OFFSET     get_link_var(UPPER_DIR_OFFSET)

#define _TOTAL_PAGE_NUMBER    get_link_var(TOTAL_PAGE_NUMBER)
#define _TOTAL_DIR_NUMBER     get_link_var(TOTAL_DIR_NUMBER)

#define _DIRECTORY_TABLE      get_link_var(DIRECTORY_TABLE)
#define _PAGE_TABLE           get_link_var(PAGE_TABLE)
#define _PHYSICAL_DIRECTORY_TABLE  get_link_var(PHYSICAL_DIRECTORY_TABLE)
#define _PHYSICAL_PAGE_TABLE       get_link_var(PHYSICAL_PAGE_TABLE)

#endif
