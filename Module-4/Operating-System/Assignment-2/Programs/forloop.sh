#!/bin/bash

echo "Sum and average"
file=$1;
sum=0

if [ ! $# -eq 1 ];
then
  echo "Give me one parameter i.e the file"
else
 for i in $(cat "$file"); 
  do
    sum=$((sum+i))
  done;
  
echo "Sum = $sum"
echo "Average = $((sum/i))"

fi

