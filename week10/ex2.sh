#!/bin/sh

path="../week01/file.txt"

node=$(ls -i "$path" | cut -f1 -d" ")

link "$path" _ex2.txt

find ./ -inum "$node" > ex2.txt

find ./ -inum "$node" -exec rm {} \; >> ex2.txt

# last line remove file.txt so Im recreate it to upload
