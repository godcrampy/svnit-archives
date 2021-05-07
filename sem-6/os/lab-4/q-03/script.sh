if [ $# -ne 1 ]; then
  echo "usage: ./script.sh <word>"
  exit 2
fi
files=$(find . -type f)

word=$1

for file in $files; do
  res=$(grep -w $word $file)
  if [ -n "$res" ]; then
    echo $file
  fi
done
