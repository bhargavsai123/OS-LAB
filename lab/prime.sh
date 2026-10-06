#!/bin/bash

echo -n "Enter a Number : "
read n
for ((i=2; i<=n/2; i++))
do
    if [ $((n%i)) -eq 0 ]
    then
        echo "$n is not a prime number."
        exit 0
    fi
done
echo "$n is a prime number."