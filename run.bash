g++ A.cpp

for file in ./.in/*; do
	if [ $# -ne 0 ] ; then
		echo --input--
		cat $file
	fi
	
	echo --output--
	./a.out < "$file"
done