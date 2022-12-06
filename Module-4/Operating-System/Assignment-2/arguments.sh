#!/bin/bash

echo "Command line Arguments"
#numbers = $@

sum=0

for i in "$@";
do
  #echo $i
  sum=$((sum+i))
done

echo "sum is $sum"

