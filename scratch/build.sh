#!/bin/bash

GETCPUS="-D NUMCPUS=$(nproc --all)" 

gcc -Og -ggdb -Wall -Wextra $GETCPUS -o $1 $1.c
