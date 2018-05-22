#ifndef _LINK_VAR_H
#define _LINK_VAR_H

extern void _LOADER_SIZE;
extern void _LOADER_PAGE_NUMBER;
extern void _LOADER_DIR_NUMBER;

extern void _KERNEL_VIRTUAL_BASE;
extern void _KERNEL_VIRTUAL_PAGE;
extern void _KERNEL_VIRTUAL_DIR;

extern void _KERNEL_PHYSICAL_BASE;
extern void _KERNEL_PHYSICAL_PAGE;
extern void _KERNEL_PHYSICAL_DIR;

extern void _KERNEL_SIZE;
extern void _KERNEL_PAGE_NUMBER;
extern void _KERNEL_DIR_NUMBER;

extern void _TOTAL_PAGE_NUMBER;
extern void _TOTAL_DIR_NUMBER;

#define LOADER_SIZE            ((uint32_t) &_LOADER_SIZE)
#define LOADER_PAGE_NUMBER     ((uint32_t) &_LOADER_PAGE_NUMBER)
#define LOADER_DIR_NUMBER      ((uint32_t) &_LOADER_DIR_NUMBER)

#define KERNEL_VIRTUAL_BASE    ((uint32_t) &_KERNEL_VIRTUAL_BASE)
#define KERNEL_VIRTUAL_PAGE    ((uint32_t) &_KERNEL_VIRTUAL_PAGE)
#define KERNEL_VIRTUAL_DIR     ((uint32_t) &_KERNEL_VIRTUAL_DIR)

#define KERNEL_PHYSICAL_BASE   ((uint32_t) &_KERNEL_PHYSICAL_BASE)
#define KERNEL_PHYSICAL_PAGE   ((uint32_t) &_KERNEL_PHYSICAL_PAGE)
#define KERNEL_PHYSICAL_DIR    ((uint32_t) &_KERNEL_PHYSICAL_DIR)

#define KERNEL_SIZE            ((uint32_t) &_KERNEL_SIZE)
#define KERNEL_PAGE_NUMBER     ((uint32_t) &_KERNEL_PAGE_NUMBER)
#define KERNEL_DIR_NUMBER      ((uint32_t) &_KERNEL_DIR_NUMBER)

#define TOTAL_PAGE_NUMBER      ((uint32_t) &_TOTAL_PAGE_NUMBER)
#define TOTAL_DIR_NUMBER       ((uint32_t) &_TOTAL_DIR_NUMBER)

#endif
