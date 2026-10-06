#!/bin/bash
echo -n "Enter a Number : "
read n
x=$n
r=0
while [ $x -gt 0 ]
do
    r=$((r*10 + x%10))
    x=$((x/10))
done
if [ $r -eq $n ]
then
    echo "$n is a palindrome number."
else
    echo "$n is not a palindrome number."
fi 