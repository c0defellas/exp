#include <stdio.h>

/* xxx kernel headers */
#include "xxx/types.h"
#include "xxx/vesa.h"
#include "xxx/term.h"

/* xxx headers */
#include "dat.h"
#include "fns.h"

Term *term;

int main() {
        Term t;

        term = &t;

        terminit(term);

        Reg reg;

        newreg(&reg);

        printRegs32(&reg);
        printRegs16(&reg);

        return 0;
}
