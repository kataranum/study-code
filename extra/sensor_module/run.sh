#!/bin/bash

FILE_NAME="sensor_module"

gcc -Wall -Wextra "$FILE_NAME.c" -o "$FILE_NAME.out"
./$FILE_NAME.out
