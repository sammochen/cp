#!/bin/bash

if [[ $# -eq 0 ]] ; then
	echo "didnt work"
	exit 1
fi

if [[ ! -e ./templates/$1.cpp ]] ; then
	echo "doesnt exit"
	exit 1
fi

cp ./templates/$1.cpp A.cpp

rm -r .in

mkdir .in

gedit A.cpp >/dev/null &

