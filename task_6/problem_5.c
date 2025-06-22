#include <stdio.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

int compareDates(struct Date *date1, struct Date *date2) {
    if (date1->year == date2->year && 
        date1->month == date2->month && 
        date1->day == date2->day) {
        return 1; // Dates are equal
    }
    return 0; // Dates are not equal
}

int main() {
    struct Date date1, date2;
    struct Date *ptr1 = &date1;
    struct Date *ptr2 = &date2;
    
    // Input for first date
    printf("Enter first date (DD MM YYYY): ");
    scanf("%d %d %d", &ptr1->day, &ptr1->month, &(*ptr1).year);
    
    // Input for second date
    printf("Enter second date (DD MM YYYY): ");
    scanf("%d %d %d", &ptr2->day, &ptr2->month, &ptr2->year);
    
    // Compare dates and display result
    if (compareDates(ptr1, ptr2)) {
        printf("Dates are equal\n");
    } else {
        printf("Dates are not equal\n");
    }
    
    return 0;
}