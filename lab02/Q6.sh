#! /bin/bash
read -p "Enter number: " num
num1=0
num2=1
echo 0
echo $num2
for i in $(seq $num);
do
	num3=$(( $num1 + $num2 ))
	echo $num3
	num1=$num2
	num2=$num3
done;
