cp ./templates/og.cpp A.cpp
read -p "Are you sure? "

if [[ $REPLY == [[:alnum:]] ]] ; then
	echo new!
	rm ./.in/* 2> /dev/null
	rm ./a.out 2> /dev/null
	gedit A.cpp >/dev/null &
fi

