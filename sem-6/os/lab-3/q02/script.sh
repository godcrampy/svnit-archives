read -p "Enter a number: " num

if [ $num -lt 1 ]; then
  echo "not allowed!"
  exit 1
fi

i=1
printf "The divisiors of $num are: "
for ((i; i <= $num; )); do
  if [ $(expr $num % $i) -eq 0 ]; then
    echo -n "$i "
  fi
  i=$(expr $i + 1)
done
echo ""
