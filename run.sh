#!/bin/bash

g++ A.cpp

if [[ $? -ne 0 ]] ; then
	exit 1
fi

empty=0

if [[ $(echo ./.in/*) == './.in/*' ]] ; then
	echo made empty
	>./.in/blank
	empty=1
fi

for file in ./.in/*; do
	if [ $# -ne 0 ] ; then
		echo --input--
		cat $file
	fi
	
	echo --output--
	./a.out < "$file"
done

if [[ empty == 1 ]] ; then
	rm ./.in/blank
fi

