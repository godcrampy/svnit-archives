#!/bin/bash

re='[0-9]'
if ! [[ $1 =~ $re ]]; then
  echo "error: Not a number" >&2
  exit 1
fi

if ! [[ $2 =~ $re ]]; then
  echo "error: Not a number" >&2
  exit 1
fi

if ! [[ $3 =~ $re ]]; then
  echo "error: Not a number" >&2
  exit 1
fi

arr=($1 $2 $3)
max=${arr[0]}
for n in "${arr[@]}"; do
  ((n > max)) && max=$n
done
echo "Max:" $max
