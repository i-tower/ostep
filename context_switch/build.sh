#!/bin/bash




gcc -Og -ggdb -Wno-unused-result -Wall -Wextra $asan -o $1 $1.c
