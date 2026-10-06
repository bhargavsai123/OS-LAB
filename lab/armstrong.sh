#!/bin/bash
echo -n "Enter a Number : "
read n
t=$n
sum=0
d=0
while [ $t -gt 0 ]
do
    t=$((t/10))
    d=$((d+1))
done
t=$n
while [ $t -gt 0 ]
do
    r=$((t%10))
    sum=$((sum + r**d))
    t=$((t/10))
done
if [ $sum -eq $n ]
then
    echo "$n is an Armstrong number."
else
    echo "$n is not an Armstrong number."
fi