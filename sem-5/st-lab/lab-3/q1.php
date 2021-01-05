<?php
$year = 2016;

if($year % 4 == 0) {
  if($year % 100 == 0 && $year % 400 != 0) {
    echo "not a leap year\n";
  } else {
    echo "leap year\n";
  }
} else {
  echo "not a leap year\n";
} 
?>