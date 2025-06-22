#include <stdio.h>

struct employee {
    char* name ;
    int age;
    int salary;
};

int main() {
    struct employee emp;
    emp.name = "John Doe";
    emp.age = 30;
    emp.salary = 50000;

    printf("Employee Name: %s\n", emp.name);
    printf("Age: %d\n", emp.age);
    printf("Salary: %d\n", emp.salary);

    return 0;
}