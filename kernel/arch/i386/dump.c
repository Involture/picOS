#include <stdio.h>

#include <kernel/dump.h>

void dump_print_reg (struct dump_as_reg_dump* dump) {
  printf("eax : %w | ebx : %w | ecx : %w | edx : %w\n", 
         &(dump->eax), 4, &(dump->ebx), 4
         &(dump->ecx), 4, &(dump->edx), 4);
  printf("esp : %w | ebp : %w | esi : %w | edi : %w\n", 
         &(dump->esp), 4, &(dump->ebp), 4
         &(dump->esi), 4, &(dump->edi), 4);
}

void dump_print_seg (struct dump_as_seg_dump* dump) {
  printf("cs : %x | ds : %x | es : %x | fs : %x | gs : %x | ss : %x\n",
         dump->cs, dump->ds, dump->es, dump->fs, dump->gs, dump->ss);
}

void dump_print_interrup (struct dump_as_interrupt_dump* dump) {
  printf("errcode : %w | eip : %w\n", &(dump->error_code), &(dump->eip)); 
  printf("%w cs : %w | eflags : %w\n", &(dump->cs), &(dump->eflags);
}
