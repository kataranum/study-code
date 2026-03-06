#!/bin/bash

FILE_NAME="spaceship_dashboard"

gcc -Wall -Wextra "$FILE_NAME.c" -o "$FILE_NAME.out"
./$FILE_NAME.out
