#!/bin/sh

gcc -pthread ex4.c -o ex4

: > ex4.txt

for i in 1 2 4 10 100
do
  ./ex4 10000000 $i
done
