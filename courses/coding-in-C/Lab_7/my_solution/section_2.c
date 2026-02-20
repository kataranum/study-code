#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    double value;
    struct Node *p_next;
} typedef Node;

Node ll_empty(void) {
    Node node;
    node.value = 0.0;
    node.p_next = NULL;

    return node;
}

Node* ll_find_tail(Node *p_node) {
    while (1) {
        if (p_node->p_next == NULL) {
            return p_node;
        }

        p_node = p_node->p_next;
    }
}

Node* ll_append(double value, Node *p_head) {
    Node *p_tail = ll_find_tail(p_head);

    Node *p_new = malloc(sizeof(Node));
    p_new->value = value;
    p_new->p_next = NULL;

    p_tail->p_next = p_new;

    return p_new;
}

void fill_array_rnd(int *p_arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        p_arr[i] = rand();
    }
}

int main(void) {
    Node head = ll_empty();

    for (int i = 0; i < 50; i++) {
        ll_append((double) i, &head);
    }

    int arr[51] = { 0 };
    fill_array_rnd(arr, 50);

    return 0;
}
