printf "%2s |  %16s | %16s\n" "N" "Bubble Sort" "Shell Sort"
printf "%s,%s,%s\n" "N" "Bubble Sort" "Shell Sort" > data.csv
printf "__________________________________________\n"
for i in {10..100000}; do
  bubble=$(./bubble $i 2>/dev/null) 
  shell=$(./shell $i 2>/dev/null)
  printf "%2d |  %16d | %16d|\n" "$i" "$bubble" "$shell"
  printf "%d,%d,%d\n" "$i" "$bubble" "$shell" >> data.csv
done
