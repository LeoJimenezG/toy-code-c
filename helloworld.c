#include <stdio.h> // Input-Output library.

int foo(double x) { return x; } // Function definition.

struct T { double a[4]; };
struct T f(void) { return (struct T){3.15}; }
double g1(double* x) { return *x; }

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

    return 0;
}
