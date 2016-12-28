#include <stdio.h>
#include <string.h> // memmove

int main() {
    int abc[] = {1, 2, 3};
    int *copy1;
    int copy2[3];

    copy1 = abc;                        // Point copy1 to same memory as abc 
    memmove(copy2, abc, 3*sizeof(int)); // Copy elements of abc to copy2 (deep copy)
    abc[0] = 0;                         // Change memory at location pointed to by abc

    printf("abc: %i, %i, %i\n", abc[0], abc[1], abc[2]);
    printf("copy2: %i, %i, %i\n", copy2[0], copy2[1], copy2[2]); // Same as original abc because did deep copy of original abc 
    printf("copy1: %i, %i, %i\n", copy1[0], copy1[1], copy1[2]); // Same as modified abc because it was always pointing to same memory as original abc
}

