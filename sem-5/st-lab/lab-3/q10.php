<?php
echo "String Functions:\n";
echo "1. Gets a character from a specified ASCII value: ";
echo chr(52)."\n";

echo "2. Split the string after each character and add a "." after each split: ";
$str = "Hello world!";
echo chunk_split($str,1,".")."\n";

echo "3, Add a backslash in front of each double quote: ";
$str = addslashes('What does "yolo" mean?');
echo $str."\n";

echo "4. Add a backslash in front of the character W: ";
$str = addcslashes("Hello World!","W");
echo $str."\n";

echo "5. Gets the ASCII value of character: ";
echo ord("hello")."\n";

echo "6. Repeat the string Wow 3 times: ";
echo str_repeat("Wow ", 3)."\n";

echo "\nMath Functions:\n";
echo "1. Gets the absolute (positive) value of a number: ";
echo abs(6.7)."\n";

echo "2. Rounds a number up to the nearest integer: ";
echo ceil(5.1)."\n";

echo "3. Gets the cosine of a number: ";
echo cos(3)."\n";

echo "4. Gets hyperbolic cosine of a number: ";
echo cosh(3)."\n";

echo "5. Gets the arc cosine of a number: ";
echo acos(0.64)."\n";

echo "6. Round numbers down to the nearest integer: ";
echo floor(0.60)."\n";

echo "\nDate Functions:\n";
echo "1. Check if several dates are valid Gregorian dates: ";
var_dump(checkdate(12,31,-400));

echo "2. Gets the default timezone: ";
echo date_default_timezone_get()."\n";

echo "3. Add 40 days to the 15th of March, 2020: ";
$date=date_create("2020-03-15");
date_add($date,date_interval_create_from_date_string("40 days"));
echo date_format($date,"Y-m-d")."\n";

echo "4. Gets a new DateTime object, and then format the date: ";
$date=date_create("2020-06-10");
echo date_format($date,"Y/m/d H:i:s")."\n";

echo "5. Gets date/time information of the current local date/time: ";
$mydate=getdate(date("U"));
echo "$mydate[weekday], $mydate[month] $mydate[mday], $mydate[year]"."\n";

echo"6. Gets current time: ";
$mytime=gettimeofday();
echo "$mytime[sec].$mytime[usec]"."\n";

?>
