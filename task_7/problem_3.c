#include <stdio.h>

// Define complex number struct with typedef
typedef struct {
    float real;
    float imag;
} t_complex;

// Function to add two complex numbers
t_complex add_complex(t_complex a, t_complex b) {
    t_complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to print a complex number
void print_complex(t_complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi\n", c.real, c.imag);
    else
        printf("%.2f - %.2fi\n", c.real, -c.imag);
}

int main() {
    t_complex num1, num2, sum;

    // Input complex numbers
    printf("Enter first complex number (real imag): ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter second complex number (real imag): ");
    scanf("%f %f", &num2.real, &num2.imag);

    // Add using function
    sum = add_complex(num1, num2);

    // Display results
    printf("\nFirst number : ");
    print_complex(num1);
    printf("Second number: ");
    print_complex(num2);
    printf("Sum          : ");
    print_complex(sum);

    return 0;
}
