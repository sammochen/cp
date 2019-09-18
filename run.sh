#!/bin/bash

g++ A.cpp

if [[ $(echo ./.in/*) == ./.in/* ]] ; then
	echo made empty
	>./.in/blank
fi

for file in ./.in/*; do
	if [ $# -ne 0 ] ; then
		echo --input--
		cat $file
	fi
	
	echo --output--
	./a.out < "$file"
done

rm ./.in/blank
