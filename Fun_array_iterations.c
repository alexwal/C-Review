#include <stdio.h>

typedef char* string; // Means: hereon, call char* string.

int main() {
    // I. 
    string list[] = {"one", "two", "three", NULL}; 
    for (string *p = list; *p != NULL; p++) { // p is a pointer to an array of strings; p itself is not an array of strings
        printf("I. %s\n", *p);
    }

    // II. without typedef 
    char *list2[] = {"one", "two", "three", NULL}; // Means: list2 is an array of (char *)s
    for (char **p = list2; *p != NULL; p++) { // p is a pointer to an array of (char *)s; again, p itself is not an array
        printf("II. %s\n", *p);
    }

}

