#!/bin/bash

echo "even odd prgm"

read num1

if [ $((num1%2)) -eq 0 ];
then
  echo "Even"
else
  echo "Odd"
fi 

#echo $num1



