#!/usr/bin/env bash

gcc -std=c23 -O0 -ggdb -Wall -Wextra -pthread -o $1 $1.c
