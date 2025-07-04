#define ABCD 2
#include <stdio.h> // Makes the preprocessor search for the file in the system.

int foo(double x) { return x; } // Function definition.

struct T { double a[4]; };
struct T f(void) { return (struct T){3.15}; }

double g1(double* x) { return *x; }

enum Colors { RED, GREEN, BLUE };

// Entry point or main function.
int main(int argc, char *argv[])
{
    int n; // int is the type specifier and n is the declarator.
    int number = 20; // This is also called a definition.

    double d = g1(f().a);  // Is this safe?

    int array[5] = {1, 2, 3, 4, 5};
    short shorty = 10;
    int integer = 30;
    long longy = 50;

    // sizeof() returns the amount of bytes required to store an object.
    int array_bytes = (int)sizeof(array);
    // %d is for decimal values
    printf("Array size: %d bytes OR %d bits\n", array_bytes, array_bytes * 8);

    int array_elements = sizeof(array) / sizeof(array[0]);
    printf("Array elements: %d\n", array_elements);

    // %zu is for size_t values
    int short_size = (int)sizeof(shorty);
    printf("Short size: %d bytes OR %d bits\n", short_size, short_size * 8);
    int int_size = (int)sizeof(integer);
    printf("Int size: %d bytes OR %d bits\n", int_size, int_size * 8);
    int long_size = (int)sizeof(longy);
    printf("Long size: %d bytes OR %d bits\n", long_size, long_size * 8);

    #ifdef ABCD
        printf("1: yes\n");
    #else
        printf("1: no\n");
    #endif

    #ifndef ABCD
        printf("2: no\n");
    #elif ABCD == 2
        printf("2: yes\n");
    #else
        printf("2: no\n")
    #endif

    int k = 2;
    switch (k) {
        case 1:
            printf("Case 1\n");
            break;
        case 2:
            printf("Case 2 and");
        case 3:
            printf(" Case 3\n");
            break;
        default:
            printf("Case 0\n");
    }

    int n1 = 0;
    while (n1 < 10) {
        printf("Iteration: %d\n", n1);
        ++n1;
    }

    int n2 = 0;
    do {
        printf("Iteration: %d\n", n2);
        ++n2;
    } while (n2 < 10);

    enum Colors color = GREEN;

    switch (color) {
        case RED:
            printf("Color RED: %d\n", color);
            break;
        case GREEN:
            printf("Color GREEN: %d\n", color);
            break;
        case BLUE:
            printf("Color BLUE: %d\n", color);
            break;
        default:
            printf("Color WHITE: %d\n", color);
            break;
    }

    return 0;
}
