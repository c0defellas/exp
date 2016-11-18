/**
 * common data types
 */

#include <stdint.h>

/* basic types */
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

/* Reg hold processor registers */
typedef struct {
        i32 eax, ebx, ecx, edx;
        i32 eip, ebp, esi, edi;
        i32 esp;

        i16 cs, ds, es, fs, gs;
} Reg;
