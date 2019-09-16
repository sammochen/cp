

if [ $# -le 1 ] ; then
	echo "not enough"
	exit 1
fi

if [ $1 == "cf" ] ; then
	folder="codeforces"
fi

if [ $1 == pe ] ; then
	folder="projecteuler"
fi


cp A.cpp ~/problem-solving/$folder/$2.cpp

echo "saved" $2

message=$(echo update $(date +"%d-%m-%y"))
echo $message

cd ~/problem-solving
git add .
git commit -m "$(echo $message)"
git push


