#!/bin/bash

if [[ $# -eq 0 ]] ; then
	cp ./templates/include.cpp A.cpp
	cat ./templates/header.cpp >> A.cpp
	cat ./templates/og.cpp >> A.cpp
	
	exit 0
fi

name="A"

if [[ $# -eq 2 ]] ; then
	name=$2
fi

if [[ ! -e ./templates/$1.cpp ]] ; then
	echo "doesnt exit"
	exit 1
fi

cp ./templates/include.cpp $name".cpp"
cat ./templates/header.cpp >> $name".cpp"
cat ./templates/$1.cpp >> $name".cpp"
cat ./templates/og.cpp >> $name".cpp"



