#!/bin/bash

if [ $# -le 1 ] ; then
	echo "not enough"
	exit 1
fi

if [ $1 == "cf" ] ; then
	folder="codeforces"
elif [ $1 == pe ] ; then
	folder="projecteuler"
else 
	echo "not recognised"
fi

cp A.cpp ~/problem-solving/$folder/$2.cpp

message=$(echo added $2)
echo $message

cd ~/problem-solving
git add .
git commit -m "$(echo $message)"
git push


