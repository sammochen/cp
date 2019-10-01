#!/bin/bash

g++ -std=c++17 A.cpp

if [[ $? -ne 0 ]] ; then
	exit 1
fi

rm ./.in/blank

empty=0

if [[ ! $(ls -A ./.in/) ]] ; then
	echo made empty
	>./.in/blank
	empty=1
fi

for file in ./.in/*; do
	if [ $# -ne 0 ] ; then
		echo --input--
		cat $file
	fi
	
	echo --output $file --
	./a.out < "$file"
done

if [[ -e ./.in/blank ]] ; then
	rm ./.in/blank
fi

rm a.out
