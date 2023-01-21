#!/bin/bash
#

function addition(){
  echo "Addition of $1 and $2 is $(($1 + $2))";
}

function substraction(){
  echo "Substraction of $1 and $2 is $(($1 - $2))";
}

function multiplication(){
  echo "Multiplication of $1 and $2 is $(($1 * $2))"
}

function division(){
  echo "Division of $1 and $2 is $(($1 / $2))"
}

echo "Calculator functions: addition substraction mulitplication division"
"$@"

