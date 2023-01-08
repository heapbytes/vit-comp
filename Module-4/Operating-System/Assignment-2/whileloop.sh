#!/bin/bash
#
num=1
while [ $num -le $1 ]; do
  echo $num;
  num=$((num+1))
done

