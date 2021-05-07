#! /bin/bash

read -p "Enter lower range: " first
read -p "Enter upper range: " second

for ((i = $first; i <= $second; ++i)); do
  mod=$((i % 2))
  if [ "$mod" -eq "0" ]; then
    echo $i
  fi
done
