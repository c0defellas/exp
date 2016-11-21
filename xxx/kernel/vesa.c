#include "xxx/types.h"

void putchar(uint8 x, uint8 y, char c, uint16 color) {
     volatile uint16 * where;
     where = (volatile uint16 *)0xB8000 + (y * 80 + x) ;
     *where = c | (color << 8);
}

uint16 putn(uint8 x, uint8 y, char *s, uint16 sz, unsigned color) {
        uint16 i = 0;

        for (i = 0; i < sz; i++) {
                putchar(x+i, y, s[i], color);
        }

        return i;
}

uint16 putstr(uint8 x, uint8 y, char *s, uint8 color)
{
        return putn(x, y, s, strlen(s), color);
}
