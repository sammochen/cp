#!/bin/bash

./compile.sh

if [ $# == 0 ] ; then
    for file in $(echo in*)
    do
	    cat $file | ./a.out
    done
else 
    cat "$1" | ./a.out
fi