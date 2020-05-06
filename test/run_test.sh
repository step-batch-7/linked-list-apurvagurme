#! /bin/bash

mkdir -p bin

rm -rf *.o
gcc -c ./test.c
gcc -c ../list.c
gcc -o ./bin/$1 *.o
rm -rf *.o
./bin/$1