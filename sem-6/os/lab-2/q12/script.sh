#!/bin/bash

read -p "Enter number: " num
sum=0

while [ $num -gt 0 ]; do
  mod=$((num % 10))  # split
  sum=$((sum + mod)) # add
  num=$((num / 10))  # divide num by 10.
done

echo "Sum of digits of number: $sum"
