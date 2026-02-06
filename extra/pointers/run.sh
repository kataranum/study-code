#!/bin/bash

FILE_NAME="pointers"

gcc -Wall -Wextra "$FILE_NAME.c" -o "$FILE_NAME.out"
./$FILE_NAME.out
