#!/bin/sh

echo Enter subscriber number:
read -r n

gcc subscriber.c -o subscriber
for i in $(seq 1 "$n"); do gnome-terminal -- ./subscriber $i; done

gcc publisher.c -o publisher
gnome-terminal -- ./publisher $n
