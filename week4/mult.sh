#!/bin/bash

echo -n "Enter Number : "
read n
for((i=1;i<=10;i++))
do
	echo "$n X $i = $(($n*$i))"
done

