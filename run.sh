#!/bin/bash

g++ A.cpp

if [[ $? -ne 0 ]] ; then
	exit 1
fi

empty=0

if [[ ! -e ./.in/in1 ]] ; then
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

if [[ -e ./in/blank ]] ; then
	rm ./.in/blank
fi

rm a.out
