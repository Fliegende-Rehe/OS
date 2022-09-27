#!/bin/sh

gcc ex3.c -o ex3

echo Enter number of processes:
read -r n

./ex3 "$n" &
