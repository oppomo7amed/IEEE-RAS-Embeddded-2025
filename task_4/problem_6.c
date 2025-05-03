#include <stdio.h>

int main(){

int a = 7;
int *aPtr = &a; // set aPtr to the address of a

printf("Address of a is %p\nValue of aPtr is %p\n\n", &a, aPtr); //this line prints the address of the variable "a" 
                                                                 // because &a and aPtr are both = the adress of "a"

printf("Value of a is %d\nValue of *aPtr is %d\n\n", a, *aPtr);  //this line prints the value of the variable "a" 
                                                                 // and for the second one "*aPtr" point the value "a"
printf("Showing that and & are complements of each other\n");

printf("&*aPtr = %p\n*&aPtr = %p\n", &*aPtr, *&aPtr); //this line prints the address of the variable "a" 
// the first one "&*aPtr" prints the adress of "*aPtr" 
// the second one "*&aPtr" takes the address of "aPtr" by "&", then dereferences it to get the value at that address, which is the address of "a" stored in "aPtr"
}