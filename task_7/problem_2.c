#include <stdio.h>

// Rename primitive data types
typedef char            t_c8;    // signed 8-bit char
typedef unsigned char   t_uc8;   // unsigned 8-bit char

typedef short           t_i16;   // signed 16-bit int
typedef unsigned short  t_ui16;  // unsigned 16-bit int

typedef int             t_i32;   // signed 32-bit int
typedef unsigned int    t_ui32;  // unsigned 32-bit int

typedef long long       t_i64;   // signed 64-bit int
typedef unsigned long long t_ui64; // unsigned 64-bit int

typedef float           t_f32;   // 32-bit float
typedef double          t_f64;   // 64-bit double
typedef long double     t_f128;  // extended precision float

typedef void            t_void;  // void type

int main() {
    printf("Size of t_c8   : %zu bytes\n", sizeof(t_c8));
    printf("Size of t_uc8  : %zu bytes\n", sizeof(t_uc8));
    printf("Size of t_i16  : %zu bytes\n", sizeof(t_i16));
    printf("Size of t_ui16 : %zu bytes\n", sizeof(t_ui16));
    printf("Size of t_i32  : %zu bytes\n", sizeof(t_i32));
    printf("Size of t_ui32 : %zu bytes\n", sizeof(t_ui32));
    printf("Size of t_i64  : %zu bytes\n", sizeof(t_i64));
    printf("Size of t_ui64 : %zu bytes\n", sizeof(t_ui64));
    printf("Size of t_f32  : %zu bytes\n", sizeof(t_f32));
    printf("Size of t_f64  : %zu bytes\n", sizeof(t_f64));
    printf("Size of t_f128 : %zu bytes\n", sizeof(t_f128));
    return 0;
}
