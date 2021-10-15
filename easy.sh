#!/bin/bash
./_compile.sh
if [ $? -ne 0 ] ; then
    exit 1
fi

if [ $# == 0 ] ; then
    for file in $(echo *.in)
    do
	    cat $file | ./a.out
    done
else 
    cat "$1" | ./a.out
fi