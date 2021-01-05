<?php

$a = 71;
$b = 12;
$op = "*";

echo $a." ".$op." ".$b." = ";
switch($op) {
  case "+":
  echo ($a + $b);
  break;
  case "-":
  echo ($a - $b);
  break;
  case "*":
  echo ($a * $b);
  break;
  case "/":
  echo ($a/$b);
}
echo "\n";
?>
