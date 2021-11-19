#!/bin/bash
echo "> Easy - yes debug"

rm a.out
g++ -std=c++14 -DSAM A.cpp 

if [ $? -ne 0 ] ; then
    exit 1
fi

if [ $# == 0 ] ; then
    for file in $(echo *.in)
    do
	    time cat $file | ./a.out
    done
else 
    time cat "$1" | ./a.out
fi