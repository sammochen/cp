#!/bin/bash
echo "> Hard - no debug"
rm a.out
g++ -Wall -Wextra -pedantic -std=c++14 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector A.cpp 

if [ $? -ne 0 ] ; then
    echo "------------ compile failure"
    exit 1
fi

    echo "------------ compile success"


if [ $# == 0 ] ; then
    for file in $(echo *.in)
    do
	    time cat $file | ./a.out
    done
else 
    time cat "$1" | ./a.out
fi