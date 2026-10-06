#!/bin/bash
echo -n "Enter a Number : "
read n
bin=""
while [ $n -gt 0 ]
do
    rem=$((n%2))
    bin="$rem$bin"
    n=$((n/2))
done
echo "Binary representation: $bin"