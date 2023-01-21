echo "Enter Size of Array : "
read n

echo "Enter Number : "
i=0
while [ $i -lt $n ]
do
  read arr[$i]
  i=`expr $i + 1`
done

sum=0
for i in ${arr[@]}
do
  sum=`expr $sum + $i`
done

echo "Sum of array is $sum"
