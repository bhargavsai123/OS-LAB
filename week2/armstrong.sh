#!/bin/bash
echo -n "Enter Number : "
read n
t=$n
sum=0
d=0
x=$n
while [ $x -gt 0 ]
do
	x=$((x/10))
	d=$((d+1))
done	
while [ $n -gt 0 ]
do
	rem=$((n%10))
	a=1
	for((i=0;i<$d;i++))
	do
		a=$((a*rem))
	done
	sum=$((sum+a))
	n=$((n/10))
done
if [ $sum -eq $t ]
then
	echo "$t is a Armstrong Number."
else
	echo "$t is not an Armstrong Number."
fi

