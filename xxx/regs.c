/**
 * get register info
 */

#include <stdint.h>
#include "types.h"

/* 32bit registers */

i32 eax() {
        /* by calling convention */
}

i32 ebx() {
        asm("mov eax, ebx");
}

i32 ecx() {
        asm("mov eax, ecx");
}

i32 edx() {
        asm("mov eax, edx");
}

i32 eip() {
        asm("__geteip: mov eax, [esp]\n"
            "          ret\n"
            "call __geteip");
}

i32 esp() {
        asm("mov eax, esp");
}

i32 ebp() {
        asm("mov eax, ebp");
}

i32 esi() {
        asm("mov eax, esi");
}

i32 edi() {
        asm("mov eax, edi");
}
