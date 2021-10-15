
if [ $# == 0 ] ; then
    echo "Specify the number of tests pls"
    exit
fi

if [ $1 -lt 1 ] ; then
    echo "Your arg ($1) is not positive"
    exit
fi

rm *.in
for x in $(seq $1) ; do
    echo "Creating $x.in"
    touch $x.in
done
