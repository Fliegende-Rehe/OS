#!/bin/sh

gcc ex2.c -o ex2

(./ex2 &) && (top -d 1 -n 10)