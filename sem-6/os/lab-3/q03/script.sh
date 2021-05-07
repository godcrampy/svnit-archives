hour=$(date +%H)

if [ $hour -lt 12 ]; then
  echo Good morning
elif [ $hour -lt 18 ]; then
  echo Good afternoon
else
  echo Good evening
fi
