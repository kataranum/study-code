#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Node {
    double value;
    struct Node *p_next;
} typedef Node;

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

void ll_delete(Node *p_head) {
    Node *p_next = p_head->p_next;

    while (p_next != NULL) {
        free(p_head);
        p_head = p_next;
        p_next = p_head->p_next;
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
    int *p_src = p_arr + index;
    int *p_dest = p_src + 1;
    long n = (size - index) * sizeof(int);
    memcpy(p_dest, p_src, n);
    p_arr[index] = value;
}

void print_array(int *p_arr, int size) {
    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] = %d\n", i, p_arr[i]);
    }
}

int main(void) {
    Node *p_head = ll_alloc_new(0.0, NULL);

    for (int i = 0; i < 50; i++) {
        ll_append((double) i+1, p_head);
    }

    int int_rnd = rand();

    int arr[51] = { 0 };
    fill_array_rnd(arr, 50);
    insert_array(arr, 50, 3, int_rnd);
    ll_insert_at_index(p_head, 3, int_rnd);

    print_array(arr, 51);
    ll_print_all(p_head);

    ll_delete(p_head);
    p_head = NULL;

    // whether linked list or array is faster for insertion depends on the
    // circumstance, but I'd say on average linked list should be faster.

    // For linked list, the correct node needs to be found first which has O(n)
    // complexity. Furthermore, the nodes are probably all over the memory so
    // the CPU suffers more cache misses, which slow things down. Though, when
    // the node has been found, inserting a new one is a relatively simple
    // process, the speed bottleneck here probably being the syscall for
    // allocating more memory.

    // For dynamic arrays (I'll call them vectors), the memory location of the
    // index to insert is known immediately, as a vector is all in one memory
    // location. The costly operation is to move all leading items one to the
    // right to make room for the new element. Though, there is less of a risk
    // for cache misses like in Linked lists.
    // Though vectors need to also check if they still have enough allocated
    // capacity. If they run out, they need to realloc(), which costs additional
    // time. A realloc also has a chance that the whole array needs to be copied
    // to a completely different memory location, which again slows down things
    // a lot. Unfortunately, one cannot predict when or how many times this
    // would happen.

    // So I'd say generally for inserting things near the end of the list,
    // vectors should be quicker, and for inserting things in a very large list
    // or inserting stuff at the beginning, linked lists perform better.

    return 0;
}
