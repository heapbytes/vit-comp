#!/bin/bash

num=$1
fibo=0
fibo1=1

for((i=1;$i<=$num;i=$i+1));
do 
  sum=$((fibo+fibo1))
  #fibo=$((fibo+i))
done

echo "Fibonacci of $1 is $fibo"
