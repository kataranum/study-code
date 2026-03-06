#include <stdio.h>
#include <assert.h>
#include <string_utils.h>

void test_custom_len(void) {
    assert(custom_len("abcd") == 4);
    assert(custom_len("") == 0);
    assert(custom_len("hello world\n") == 12);
}

int main(void) {
    test_custom_len();

    printf("All tests successful.\n");
    return 0;
}
