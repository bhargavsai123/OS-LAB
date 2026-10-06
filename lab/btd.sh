#!/bin/bash
echo -n "Enter Number : "
read bno
n=0
p=1
while [ $bno -gt 0 ]
do
    r=$((bno%10))
    n=$((n + r*p))
    bno=$((bno/10))
    p=$((p*2))
done
echo "Decimal representation: $n"