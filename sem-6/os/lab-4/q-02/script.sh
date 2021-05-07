if [ $# -eq 0 ]; then
  echo "usage: ./script.sh [<dirs>,..]"
  exit 2
fi


for filename in "$@"; do
  if [ -d "$filename" ]; then
    find $filename -depth -maxdepth 1 >q2.txt
    [ -f "count.txt" ] && rm count.txt
    [ -f "final.txt" ] && rm final.txt
    echo "List of sub-directories & count of top level files in $filename"
    echo "Directory,Count" >>count.txt
    while read line; do
      if [[ $filename != $line ]]; then
        count=0
        for entry in "$line"/*; do
          [ -f "$entry" ] && count=$(($count + 1))
        done
        file=$(echo basename $line)
        new="$file,$count"
        $new >>count.txt
      fi
    done <q2.txt

    while IFS=, read -r a b; do echo "$a $b" >>final.txt; done <count.txt
    awk '{printf "|%-25s|%10s|\n",$1,$2}' final.txt
    echo ""
  else
    echo "$fileName is not a directory"
  fi
done

rm *.txt