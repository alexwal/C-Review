#include <stdio.h>

void set1(int of_array[], int index, int to_value) {
    of_array[index] = to_value;
}

void set2(int *of_array, int index, int to_value) {
    of_array[index] = to_value;
}

int main() {
    // This demonstrates that C arrays are pointers.
    // Normally, C functions are passed copies of their
    // arguments. Since a copy of a pointer is that same
    // memory address, we are able to change arrays (i.e.,
    // pointers), by directly passing them into functions.

    int x[] = {1, 2, 3, 4};
    printf("Before:\n%d %d %d %d\n", x[0], x[1], x[2], x[3]);
    // prints 1 2 3 4

    set1(x, 2, 7);
    printf("After (set1):\n%d %d %d %d\n", x[0], x[1], x[2], x[3]);
    // prints 1 2 7 4

    set2(x, 2, 6);
    printf("After (set2):\n%d %d %d %d\n", x[0], x[1], x[2], x[3]);
    // prints 1 2 6 4
}

