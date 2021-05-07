#! /bin/bash

read -p "Enter number: " num
re='[0-9]'
if ! [[ $num =~ $re ]]; then
  echo "error: Not a number" >&2
  exit 1
fi

fact=1

while [ $num -gt 1 ]; do
  fact=$((fact * num))
  num=$((num - 1))
done

echo "Factorial of number is: $fact"
