rm a.out
g++ -std=c++11 -Wall -DSAM A.cpp 

if [ $? -eq 0 ] ; then 
    echo "---compile success"
else 
    echo "---compile failure"
    exit 1
fi