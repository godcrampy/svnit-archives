if [ $# -ne 1 ]; then
  echo "usage: ./script.sh <filename>"
  exit 2
fi
filename=$1

ls -ld $filename >temp.txt
file=temp.txt
res=$(cat "$file")
type=$(echo $res | cut -c1-1)
case $type in
"-") echo "It is a regular file." ;;
"d") echo "It is a directory." ;;
"c") echo "It is a character device file" ;;
"l") echo "It is a symbolic link." ;;
"s") echo "It is a local socket file." ;;
"b") echo "It is a block device file." ;;
"p") echo "It is a named pipe." ;;
*) echo "It is not a valid type." ;;
esac

rm temp.txt