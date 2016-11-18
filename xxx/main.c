#include <stdio.h>

void printRegs() {
        printf("eax=%08x\tesp=%08x\n", eax(), esp());
        printf("ebx=%08x\tebp=%08x\n", ebx(), ebp());
}

int main() {
        printf("xxx v0.0.1\n");

        printRegs();

        return 0;
}
