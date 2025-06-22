#include <stdio.h>

typedef struct {
    char name[10];
    int age;
    char color[10];
} Dog;

typedef struct {
    char name[10];
    char color[10];
    int age;
} Cat;

int main() {
    printf("Size of Dog struct: %zu bytes\n", sizeof(Dog));
    printf("Size of Cat struct: %zu bytes\n", sizeof(Cat));
    return 0;
}

/*
Memory padding explanation:
- Structs in C may have padding bytes inserted by the compiler to ensure that each member is properly aligned in memory.
- For example, 'int' usually requires 4-byte alignment. If a 'char' array is followed by an 'int', the compiler may add padding after the array to align the 'int'.
- This makes the struct larger than the sum of its members' sizes.
- Padding improves access speed on most hardware architectures.
- knowing that my memory type is 64 bits, my output will be:
Size of Dog struct: 28 bytes 
Size of Cat struct: 24 bytes
*/