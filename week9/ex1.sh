#!/bin/sh

gcc ex1.c -o ex1

for i in 10 50 100
do
  echo "\n"$i page frames: >> ex1.txt
  ./ex1 $i >> ex1.txt
done
