if [ ! -f num.txt ]; then
	echo 0 > num.txt
fi

count="$(tail -1 num.txt)"
count=`expr $count + 1`
while [ $count -lt 100 ]
do
	if ! ln num.txt num.lock; then
	exit
	fi
	echo $count >> num.txt
	count=`expr $count + 1`
	rm num.lock
done

