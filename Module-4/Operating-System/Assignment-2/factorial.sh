#!/bin/bash
#
echo "Factorial"
#echo $1
#

fac=1
i=1
a=$1

while [ a -lt $1 ];
do 
  fact=$(( fact * $i ))
  $i++
done
/
