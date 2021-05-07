if [ $# -ne 2 ]; then
  echo "2 command line arguments are required"
  exit 1
fi

word=$1
num=$2

i=0
for ((i; i < $num; )); do
  echo "$word"
  i=$(expr $i + 1)
done
