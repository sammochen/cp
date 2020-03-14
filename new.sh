#!/bin/bash

if [[ $# -eq 0 ]] ; then
	echo "didnt work"
	exit 1
fi

name="A"

if [[ $# -eq 2 ]] ; then
	name=$2
fi

if [[ ! -e ./templates/$1.cpp ]] ; then
	echo "doesnt exit"
	exit 1
fi

cp ./templates/$1.cpp $name".cpp"



