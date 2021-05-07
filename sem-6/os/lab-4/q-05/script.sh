count=0
for arg in "$@"; do
  if [ -d $arg ]; then
    res=$(find $arg -type f)
    for file in $res; do
      ls -ld $file >q1.txt
      fileNew=q1.txt
      res=$(cat "$fileNew")
      type=$(echo $res | cut -c1-1)
      if [ $type == "-" ]; then

        size=$(du -sc $file | tail -n 1 | cut -c1-1)
        count=$(($count + $size))

      fi
    done
  fi
done

rm q1.txt
echo "Disk Space: $count"
