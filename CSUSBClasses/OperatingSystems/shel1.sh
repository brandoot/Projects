#!/bin/bash
#shel1.sh
city="Fremont"
name=CSE
course="CSE4600 OS"
capacity=30
grade=3.8
passed=true
echo $city
echo "Enter Age"
read age
echo "Your age is:" $age
echo "Enter a number"
read VAR1
echo "Enter another number"
read VAR2
let sum=VAR1+VAR2
echo "Sum of your numbers are: $sum"
if [ $sum -lt 0 ]
then
	echo "Your number is less than 0."
else
	echo "Your number is greater than 0."
fi
