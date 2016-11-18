/**
 * get register info
 */

#include <stdint.h>
#include "dat.h"

#define LSW(r32) (r32 & 0xffff)    /* least significant word */
#define MSW(r32) (i16(r32 >> 4))   /* most significant word */

void newreg(Reg *reg) {
        reg->eax = eax();
        reg->ebx = ebx();
        reg->ecx = ecx();
        reg->edx = edx();
        reg->eip = eip();
        reg->ebp = ebp();
        reg->esi = esi();
        reg->edi = edi();

        reg->esp = esp();

        reg->cs = cs();
        reg->ds = ds();
        reg->es = es();
        reg->fs = fs();
        reg->gs = gs();
}

void printRegs32(Reg *reg) {
        printf("eax=%08x\tesp=%08x\n", reg->eax, 0);
        printf("ebx=%08x\tebp=%08x\n", reg->ebx, reg->ebp);
        printf("ecx=%08x\tesi=%08x\n", reg->ecx, reg->esi);
        printf("edx=%08x\tedi=%08x\n", reg->edx, reg->edi);
        printf("eip=%08x\n", reg->eip);
}

void printRegs16(Reg *reg) {
        printf("ax=%04x\tsp=%04x\n", LSW(reg->eax) , LSW(reg->esp));
        printf("bx=%04x\tbp=%04x\n", LSW(reg->ebx) , LSW(reg->ebp));
        printf("cx=%04x\tsi=%04x\n", LSW(reg->ecx) , LSW(reg->esi));
        printf("dx=%04x\tdi=%04x\n", LSW(reg->edx) , LSW(reg->edi));

        printf("cs=%04x\tds=%04x\n", reg->cs , reg->ds);
        printf("es=%04x\tfs=%04x\n", reg->es, reg->fs);
        printf("gs=%04x\n", reg->gs);

}

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
        asm("call __next\n"
            "__next: pop eax");
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

/* 16bit registers */
i16 ax() {
        asm("mov bx, ax\n"
            "xor eax, eax\n"
            "mov ax, bx");
}

i16 bx() {
        asm("xor eax, eax\n"
            "mov ax, bx");
}

i16 cs() {
        asm("xor eax, eax\n"
            "mov ax, cs");
}

i16 ds() {
        asm("xor eax, eax\n"
            "mov ax, ds");
}

i16 es() {
        asm("xor eax, eax\n"
            "mov ax, es");
}

i16 fs() {
        asm("xor eax, eax\n"
            "mov ax, fs");
}

i16 gs() {
        asm("xor eax, eax\n"
            "mov ax, gs");
}
