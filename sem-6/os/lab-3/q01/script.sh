printf "Enter a number: "
read num

echo "The prime factors are:"
for ((i = 2; i <= $num; i++)); do
  while [ $((num % $i)) == 0 ]; do
    echo $i
    num=$((num / $i))
  done
done
