#!/bin/bash
rm a.out
rm out
g++ -O2 -std=c++17 A.cpp 

cat input | ./a.out > out
cat out

