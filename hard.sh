#!/bin/bash

rm a.out
g++ -Wall -Wextra -pedantic -std=c++14 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector A.cpp 


if [ $# == 0 ] ; then
    for file in $(echo *.in)
    do
	    cat $file | ./a.out
    done
else 
    cat "$1" | ./a.out
fi