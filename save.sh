#!/bin/bash

if [ $# -ne 2 ] ; then
	echo "not enough"
	exit 1
fi

if [ $1 == cf ] ; then
	folder="codeforces"
elif [ $1 == pe ] ; then
	folder="projecteuler"
elif [ $1 == ca ] ; then
	folder="csacademy"
elif [ $1 == hr ] ; then
	folder="hackerrank"
elif [ $1 == uva ] ; then
	folder="uva"
elif [ $1 == ac ] ; then
	folder="atcoder"
elif [ $1 == aizu ] ; then
	folder="aizu"
else 
	echo "not recognised"
	exit 1
fi

cp A.cpp ../cp-submissions/$folder/$2.cpp

message=$(echo added $2)
echo $message

cd ../cp-submissions
git add .
git commit -m "$(echo $message)"
git push
