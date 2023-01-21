fact(){
  if [ "$1" -le 1 ]; then
    echo 1
  else result=$(( $1 * $(fact "$(( $1 - 1))") ))
    echo "$result"
  fi
}

num=$1
result=$(fact "$num")
echo "The factorial of $num is $result "

