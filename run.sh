#!/bin/bash

rm ./.in/blank 2> /dev/null
rm ./.in/temp 2> /dev/null
rm a.out 2> /dev/null

g++ -O2 -std=c++17 A.cpp 

if [[ $? -ne 0 ]] ; then
	echo "compilation error"
	exit 1
fi
	
if [[ $# -eq 1 ]] ; then
	echo "$1" | ./a.out
	exit 0
fi

if [[ ! "$(ls -A ./.in/)" ]] ; then
	echo " " | ./a.out 
else
	for file in ./.in/*; do
		cat $file | ./a.out
	done
fi