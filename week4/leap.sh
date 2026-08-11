#!/bin/bash

echo -n "Enter Year : "
read n
if  ((n % 400 == 0)); then
	echo "Leap Year"
elif ((n % 100 == 0)) then
	echo "Not a Leap Year"
elif ((n % 4 == 0)) then
	echo "Leap Year"
else
	echo "Not a Leap Year"
fi

