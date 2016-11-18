#include <stdio.h>
#include "dat.h"
#include "fns.h"

int main() {
        Reg reg;

        newreg(&reg);

        printRegs32(&reg);
        printRegs16(&reg);

        return 0;
}
