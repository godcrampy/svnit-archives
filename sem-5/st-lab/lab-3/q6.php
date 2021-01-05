<?php

function getBill($i) {
  $bill = 0;
  if ($i <= 50) {
    $bill = 3.50 * $i;
  } else if($i == 51 && $i <= 150) {
    $bill = 4.00 * $i;
  } else if($i = 151 && $i <= 250) {
    $bill = 5.20 * $i;
  } else {
    $bill = 6.50 * $i;
  }
  return $bill;
}

echo "Bill: ".getBill(32)."\n";
echo "Bill: ".getBill(76)."\n";
echo "Bill: ".getBill(150)."\n";
echo "Bill: ".getBill(300)."\n";
?>
