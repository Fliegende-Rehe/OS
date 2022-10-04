#!/bin/sh

gcc -pthread ex3.c -o ex3 -lm

> ex3.txt

for i in 1 2 4 10 100
do
  ./ex3 10000000 $i
done
