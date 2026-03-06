#!/bin/bash

gcc test/test_string_utils.c src/string_utils.c -I inc -o test_string_utils.out -Wall -Wextra
./test_string_utils.out
