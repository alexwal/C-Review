// You can't return an array from a function in C, only a pointer!
// Auto-allocated memory is placed on the stack and gets freed after functions return.
// Manually allocated memory with `malloc` is located on the heap and lasts after functions return.

#include <stdio.h>
#include <stdlib.h> // malloc, free, calloc

typedef struct powers {
    double base, square, cube;
} powers;

powers get_power(double in) {
    powers out = {.base   = in,                                 // 1
                  .square = in*in,
                  .cube   = in*in*in};
    return out;                                                 // 2
}

int *get_even(int count) {
    int out[count];
    for (int i=0; i < count; i++) {
        out[i] = 2*i;
    }
    return out;   // (!) bad.                                   // 3
}

int *get_even_malloc(int count) {
    int* out = malloc(count * sizeof(int));
    for (int i=0; i < count; i++) {
        out[i] = 2*i;
    }
    return out;                                                 // 4 
}

int main(){
    powers threes = get_power(3);
    int *evens = get_even(3);
    int *evens_malloc = get_even_malloc(3);
    printf("threes: %g\t%g\t%g\n", threes.base, threes.square, threes.cube);
    printf("evens: %i\t%i\t%i\n", evens[0], evens[1], evens[2]);// 5
    printf("evens_malloc: %i\t%i\t%i\n", evens_malloc[0], evens_malloc[1], evens_malloc[2]);// 6
    free(evens_malloc);                                         // 7

    // Goal of this program:
        // Create an array of `count` even numbers, return it, and print it.

    // 1, 2:    okay.

    // 3:       not okay.
        // When we call `get_even`, a new stack frame is created, and
        // the array `int out[count]` is auto-allocated on the stack. 
        // When `get_even` returns, the stack frame is closed, and
        // auto-allocated memory is cleared.
        // This is bad because we returned a pointer to memory on the stack, 
        // which is undefined behavior, because it could now be pointing
        // to anything...

    // 5:       not okay.
        // Because of the above, 5 may seg-fault or print garbage.

    // This is why we use malloc:

    // 4:       okay. 
        // Manually allocated memory, or `Malloc`d memory, is allocated
        // on the heap! This doesn't get freed when the function exits,
        // so this line is valid.

    // 6:       okay.
        // This was our original goal.

    // 7:       okay.
        // It's a good idea to free `malloc`d memory.
}

