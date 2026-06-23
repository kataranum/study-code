#!/bin/bash

set -e

g++ *.cpp -o out.out -Wall -Wextra -Wpedantic
./out.out
