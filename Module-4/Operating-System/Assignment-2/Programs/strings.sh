findLength (){
	echo "Length of $1 is : ${#1}"
	echo "Length of $2 is : ${#2}"
}

concat (){
	echo "After concatenation : "
	echo ${1}${3}${2}
}

lower (){
	res=$(echo $1 | tr '[A-Z]' '[a-z]');
	res2=$(echo $2 | tr '[A-Z]' '[a-z]');
	
	echo "Lower Case of $1 is $res"
	echo "Lower Case of $2 is $res2"
}

upper (){
	res=$(echo $1 | tr '[a-z]' '[A-Z]');
	res2=$(echo $2 | tr '[a-z]' '[A-Z]');	
	echo "Upper Case of $1 is $res"
	echo "Upper Case of $2 is $res2"
}

slice (){
	echo "Slicing $1 from  : ${1:2:4}"
}

findLength $1 $2
concat $1 $2 $3
lower $1 $2
upper $1 $2
slice $1
