<?php 
function countDigits($num) {
  $num = (string)$num;
  $sum = 0;
  for ($i = 0; $i < strlen($num); $i++){
    $sum += $num[$i]; 
  } 
  return $sum;
}

echo countDigits(1234)."\n";
?>