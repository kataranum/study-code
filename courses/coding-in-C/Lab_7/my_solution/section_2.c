#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

Node* ll_alloc_new(double value, Node* p_next) {
    Node *p_node = malloc(sizeof(Node));
    p_node->value = value;
    p_node->p_next = p_next;

    return p_node;
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

int ll_insert_at_index(Node *p_node, int index, double value) {
    for (int i = 0; i < index-1; i++) {
        if (p_node->p_next == NULL) {
            return 0;
        }

        p_node = p_node->p_next;
    }

    Node *p_next = p_node->p_next;

    Node *p_new = ll_alloc_new(value, p_next);
    p_node->p_next = p_new;

    return 1;
}

void ll_print_all(Node *p_node) {
    printf("Linked list:\n");
    int i = 0;
    while (p_node->p_next != NULL) {
        printf("Node[%d] = %f\n", i++, p_node->value);
        p_node = p_node->p_next;
    }
}

void fill_array_rnd(int *p_arr, int size) {
    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        p_arr[i] = rand();
    }
}

void insert_array(int *p_arr, int size, int index, int value) {
    // copy p_arr[index .. index+size] to p_arr[index+1 .. index+size+1]
    // effectively moving the latter part 1 position to the right.
    memcpy(p_arr + index + 1, p_arr + index, size - index);
    p_arr[index] = value;
}

void print_array(int *p_arr, int size) {
    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] = %d\n", i, p_arr[i]);
    }
}

int main(void) {
    Node head = ll_empty();

    for (int i = 0; i < 50; i++) {
        ll_append((double) i+1, &head);
    }

    int int_rnd = rand();

    int arr[51] = { 0 };
    fill_array_rnd(arr, 50);
    insert_array(arr, 50, 3, int_rnd);
    ll_insert_at_index(&head, 3, int_rnd);

    print_array(arr, 51);
    ll_print_all(&head);

    return 0;
}
