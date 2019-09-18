#!/bin/bash

if [[ $# -eq 0 ]] ; then
	echo "didnt work"
	exit 1
fi


cp ./templates/$1.cpp A.cpp
rm ./.in/* 2> /dev/null
rm ./a.out 2> /dev/null

mkdir .in
gedit A.cpp >/dev/null &

