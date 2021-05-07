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

echo "Sum:" $(($1 + $2))
