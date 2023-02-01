read -p "Enter 1st Number: " num1
read -p "Enter 2nd Number: " num2
read -p "Enter 3rd Number: " num3
if [[ $num1 < $num2 && $num1 < num3 ]];
then
	echo "$num1 is small"

elif [[ $num2 < $num1 && $num2 < num3 ]];
then
	echo "$num2 is small"

else
	echo "num3 is small"
fi
#fi is the end of the if statement