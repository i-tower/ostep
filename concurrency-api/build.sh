#!/bin/bash

gcc-14 -std=c23 -O0 -ggdb -Wall -Wextra -pthread -o $1 $1.c
