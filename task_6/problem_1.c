#include <stdio.h>

struct pet {
    char* name;
    int age;
    char* kind;
    char* food; 
    char* owner_name;
};

int main() {
    struct pet my_pet;
    my_pet.name = "Buddy";
    my_pet.age = 5;
    my_pet.kind = "Dog";
    my_pet.food = "Dog Food";
    my_pet.owner_name = "Alice";

    printf("Pet Name: %s\n", my_pet.name);
    printf("Age: %d\n", my_pet.age);
    printf("Kind: %s\n", my_pet.kind);
    printf("Food: %s\n", my_pet.food);
    printf("Owner Name: %s\n", my_pet.owner_name);

    return 0;
}