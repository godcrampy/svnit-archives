if [ $# -ne 1 ]; then
  echo "usage: ./script.sh <dir>"
  exit 2
fi
name=$1

echo "The executable files are:"
find $name -executable -type f

echo "The number of executable files are:"
find $name -executable -type f | wc -l
