#!/bin/bash

echo "Command line Arguments"
sum=0

for i in "$@";
do
  sum=$((sum+i))
done

echo "sum is $sum"

