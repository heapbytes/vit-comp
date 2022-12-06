#!/bin/bash

num1=$1
num2=$2

if [ $num1 -eq $num2 ];
then
  echo "equal"
else
  if [ $num1 -lt $num2 ];
  then 
    echo "Num2 is greater"
  else
    echo "num3 is greater"
  fi
fi
