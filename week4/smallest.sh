#!/bin/bash
echo -n "Enter First Number : "
read a
echo -n "Enter Second Number : "
read b
echo -n "Enter Third Number : "
read c
if [ $a -lt $b ]
then
	if [ $a -lt $c ]
	then
		echo -n "$a "
	else
		echo -n "$c "
	fi
else
	if [ $b -lt $c ]
	then
		echo -n "$b "
	else
		echo -n "$c "
	fi
fi
echo "is the smallest number."
