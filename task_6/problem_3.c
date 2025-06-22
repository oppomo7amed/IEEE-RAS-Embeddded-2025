#include <stdio.h>

typedef struct pet {
    char* name;
    int age;
    char* kind;
    char* food; 
    char* owner_name;
}pet;

int main() {
    pet my_pet = {"Tom", 3, "Cat", "Cat Food", "oppo"};

    printf("Pet Name: %s\n", my_pet.name);
    printf("Age: %d\n", my_pet.age);
    printf("Kind: %s\n", my_pet.kind);
    printf("Food: %s\n", my_pet.food);
    printf("Owner Name: %s\n", my_pet.owner_name);

    return 0;
}