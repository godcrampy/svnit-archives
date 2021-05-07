#!/bin/bash

echo "enter l for Number of users logged in"
echo "enter c for calendar of current year"
echo "enter d for date"
read -n1 ans
echo ""
echo "You entered:" $ans

case "$ans" in
'l')
  users=$(who | sort --key=1,1 --unique | wc --lines)
  echo "Number of users logged in:" $users
  ;;
'c')
  cal -y
  ;;
'd')
  date
  ;;
*)
  echo "Unknown charecter entered..."
  ;;
esac
