read -p "Enter a file name: " file
echo "Number of blank space in $file is: "

grep -c "^$" $file
