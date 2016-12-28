#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} *Node;
// Now we can say "struct Node node" OR "Node node"
// since both are defined!!

// With the above typedef all set,
// we'll treat a pointer to a "struct Node"
// simply as a "Node" and
// access its fields with `->`.

Node create_node(int value) {
    Node node = malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// This doesn't work becasue a copy of struct Node is input to this
// function, so we don't have knowledge of the memory address controlling
// the passed in struct Node. 
void change_struct_Node(struct Node n, int v) {
    // Passed in (shallow) copy of struct Node
    n.value = v;
}

// This works because a Node (without struct) is a memory address (ptr!),
// so we are actually getting a copy of the pointer to the struct Node.
void change_Node(Node n, int v) {
    // Passed in copy of memory address
    n->value = v;
}

int main() {
    // Node is typedef'd as a struct Node* which is just a
    // memory address, so we can easily pass a copy of this
    // address to change its memory value:
    Node node = create_node(5);
    printf("Before Node change: %i\n", node->value);
    // prints 5

    change_Node(node, 6);
    printf("After Node change: %i\n", node->value);
    // prints 6

    Node sn_ptr = create_node(7); 
    struct Node sn = *sn_ptr;
    printf("Before struct Node change: %i\n", sn.value);
    // prints 7

    // Results in no change:
    change_struct_Node(sn, 8);
    printf("After struct Node change: %i\n", sn.value);
    // prints 7

    // Results in change:
    change_Node(&sn, 8);
    printf("After &(struct Node) == Node change: %i\n", sn.value);
    // prints 8
}

