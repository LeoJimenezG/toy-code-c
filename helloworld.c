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

	return 0;
}
