#!/bin/bash
echo -n "Enter Decimal No. : "
read num
rem=1
bno=""
while [ $num -gt 0 ]
do
	rem=$((num % 2))
	bno=$rem$bno
	num=$((num / 2))
done
echo "Equivalent Binary Number : " $bno
