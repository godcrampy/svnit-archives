<?php
function printMatrix($m) {
  foreach ($m as $a) {
    foreach ($a as $i) {
      echo $i." ";
    }
    echo "\n";
  }
  echo "\n";
}

$m1 = array(
  array(1, 2, 3),
  array(4, 5, 6),
  array(7, 8, 9)
);
echo "m1: \n";
printMatrix($m1);

$m2 = array(
  array(2, 5, 8),
  array(6, 4, 7),
  array(1, 7, 5)
);
echo "m2: \n";
printMatrix($m2);
$m3 = array(array());
$m4 = array(array());

$row = 3;
$col = 3;

// a
for($i = 0; $i < $row; $i++) {
  for($j = 0; $j < $i; $j++) {
    $temp = $m1[$i][$j];
    $m1[$i][$j] = $m1[$j][$i];
    $m1[$j][$i] = $temp;
  }
}
echo "transpose: \n";
printMatrix($m1);

// b
for ($i = 0; $i < $row; $i++) { 
  for ($j = 0; $j < $col; $j++) { 
    $m3[$i][$j] = 0; 
    for ($k = 0; $k < $col; $k++) 
      $m3[$i][$j] += $m1[$i][$k] * $m2[$k][$j]; 
  } 
}
echo "multiplication: \n";
printMatrix($m3);

// c
for($i = 0; $i < $row; $i++) {
  for($j = 0; $j < $col; $j++) {
   $m4[$i][$j] = $m1[$i][$j] + $m2[$i][$j];
  }
}

echo "addition: \n";
printMatrix($m4);
?>