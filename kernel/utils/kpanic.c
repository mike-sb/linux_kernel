#include <arch/reg.h>
#include <lib/abort.h>
#include <lib/stdint.h>

/*
* API - stop kernel execution
*/
extern void kpanic(char* message, ...)
{
    va_list list;
    va_start(list, message);

    kmode(true);
    kvprintf(message, list);
    kprintf("Kernel panic!\n");
    asm_lock();
    asm_hlt();
}