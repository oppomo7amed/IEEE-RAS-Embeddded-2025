#include <stdio.h>

// Enum for days of the week (starting from Saturday)
typedef enum {
    SATURDAY,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
} t_day;

// Function to check if day is weekend or weekday
const char* check_day(t_day day) {
    if (day == SATURDAY || day == FRIDAY) {
        return "Weekend";
    } else {
        return "Weekday";
    }
}

int main() {
    // Test
    for (t_day d = SATURDAY; d <= FRIDAY; d++) {
        printf("Day %d: %s\n", d, check_day(d));
    }

    return 0;
}
