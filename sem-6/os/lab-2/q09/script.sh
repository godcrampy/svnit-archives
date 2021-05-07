#! /bin/bash

num=(5 17 20 67 1 3)
n=${#num[@]}
echo "Original array num:"
for l in "${num[@]}"; do
  printf "$l "
done

echo ""

for ((i = 0; i < ${#num[@]}; i++)); do
  for ((j = 0; j < ${#num[@]}; j++)); do
    if [[ ${num[$j]} -lt ${num[$i]} ]]; then
      tmp=${num[$i]}
      num[$i]=${num[$j]}
      num[$j]=${tmp}
    fi
  done
done

echo ""
echo "Descending order num:"
i=0
while [ $i -lt $n ]; do
  printf "${num[i]} "
  i=$((i + 1))
done

echo ""
