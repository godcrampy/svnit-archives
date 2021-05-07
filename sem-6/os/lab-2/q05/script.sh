#!/bin/bash

file1=$1
file2=$2

if [ -f "$file1" ]; then
  cat $1 >>$2
else
  echo "$file1 does not exist."
fi
