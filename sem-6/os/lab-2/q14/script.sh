#! /bin/bash

read -p "Enter number of values to show in fibonnaci series: " N

echo "The Fibonacci series is : "

a=0
b=1
for ((i = 0; i < N; i++)); do
  echo -n "$a "
  fn=$((a + b))
  a=$b
  b=$fn
done
echo ""
