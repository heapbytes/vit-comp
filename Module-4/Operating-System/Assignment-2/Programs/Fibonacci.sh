a=0
b=1
echo "Fibbonaci Series" 
echo $a
echo $b
for ((i=2 ; i<$1 ; i++))
do 
  fib=$((a+b))
  a=$b
  b=$fib
  echo $fib
done
