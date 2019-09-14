

if [ $# -eq 0 ] ; then
	echo "name pls"
	exit 1
fi

cp A.cpp ~/problem-solving/codeforces/$1.cpp

echo "saved" $1

message=$(echo update $(date +"%d-%m-%y"))
echo $message

cd ~/problem-solving
git add .
git commit -m "$(echo $message)"
git push

nautilus ~/problem-solving
