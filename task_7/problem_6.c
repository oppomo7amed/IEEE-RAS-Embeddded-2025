#include <stdio.h>

// Define a union that can hold int, float, or char
typedef union {
    int   a;
    float b;
    char  c;
} t_data;

int main() {
    t_data data;

    // Assign integer value
    data.a = 65;   // ASCII code for 'A'
    printf("After assigning int (a=65):\n");
    printf("a = %d\n", data.a);
    printf("b = %f\n", data.b);
    printf("c = %c\n\n", data.c);

    // Assign float value
    data.b = 3.14f;
    printf("After assigning float (b=3.14):\n");
    printf("a = %d\n", data.a);
    printf("b = %f\n", data.b);
    printf("c = %c\n\n", data.c);

    // Assign char value
    data.c = 'Z';
    printf("After assigning char (c='Z'):\n");
    printf("a = %d\n", data.a);
    printf("b = %f\n", data.b);
    printf("c = %c\n\n", data.c);

    // Show size of union
    printf("Size of union t_data = %zu bytes\n", sizeof(t_data));

    return 0;
}
