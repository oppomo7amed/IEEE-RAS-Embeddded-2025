#include <stdio.h>
#include <string.h>

// Struct definition
struct student_info {
    unsigned int roll_number : 4; // 4 bits (0–15)
    unsigned int age         : 8; // 8 bits (0–255)
    unsigned int marks       : 3; // 3 bits (0–7)
    char name[50];                // Fixed-size string
    char address[100];            // Fixed-size string
};

// Function to print student info
void print_student(struct student_info s) {
    printf("Roll Number: %u\n", s.roll_number);
    printf("Age: %u\n", s.age);
    printf("Marks: %u\n", s.marks);
    printf("Name: %s\n", s.name);
    printf("Address: %s\n\n", s.address);
}

int main() {
    struct student_info students[5];

    // Example data
    for (int i = 0; i < 5; i++) {
        students[i].roll_number = i + 1;
        students[i].age = 18 + i;
        students[i].marks = (i % 8);
        sprintf(students[i].name, "Student_%d", i + 1);
        sprintf(students[i].address, "Address_%d", i + 1);
    }

    // Print all 5 students
    for (int i = 0; i < 5; i++) {
        print_student(students[i]);
    }

    // Show total struct size
    printf("Size of struct student_info: %zu bytes\n", sizeof(struct student_info));
    return 0;
}
