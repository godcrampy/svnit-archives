echo "Files greater than 1000 bytes:"
find . -type f -size +1000c -ls | sort -r -n -k7
echo "Number of files:"
find . -type f -size +1000c -ls | sort -r -n -k7 | wc -l
