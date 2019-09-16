if [[ $# -eq 0 ]] ; then
	exit 1
fi


cp ./templates/$1.cpp A.cpp
rm ./.in/* 2> /dev/null
rm ./a.out 2> /dev/null
gedit A.cpp >/dev/null &

