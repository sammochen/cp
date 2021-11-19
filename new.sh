#!/bin/bash

name="A.cpp"

bottom="main"

if [[ $# -eq 0 ]] ; then
	cp ./body/defs.cpp $name
	cat ./body/$bottom.cpp >> $name
	
	exit 0
fi

if [[ ! -e ./templates/$1.cpp ]] ; then
	echo "doesnt exit"
	exit 1
fi

cp ./body/defs.cpp $name
cat ./templates/$1.cpp >> $name
cat ./body/$bottom.cpp >> $name



