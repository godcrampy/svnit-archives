#!/bin/bash

printf "Enter A charecter: "
read -n1 ans
echo ""
echo "You entered:" $ans

case $ans in

[A-Z])
  echo "Uppercase"
  ;;
[a-z])
  echo "Lowercase"
  ;;
[0-9])
  echo "Digit"
  ;;
*)
  echo "Special Symbol"
  ;;
esac

case $ans in
[AEIOUaeiou])
  echo "It is a vowel"
  ;;
*)
  echo "Not a Vowel"
  ;;
esac
