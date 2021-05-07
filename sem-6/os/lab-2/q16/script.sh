#! /bin/bash


if [ -f "$1" ]; then
  w=$(cat $1 | wc -w)
  c=$(cat $1 | wc -c)
  l=$(cat $1 | wc -l)
  echo Number of characters in $1 is $c
  echo Number of words in $1 is $w
  echo Number of lines in $1 is $l
else
  echo "$1 does not exist."
fi
