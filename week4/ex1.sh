#!/bin/bash
num=0
for i in 1 2 3 4 5 6 7 8 9 10
do
 ./ex1 $num
 let "num += 1"
done
