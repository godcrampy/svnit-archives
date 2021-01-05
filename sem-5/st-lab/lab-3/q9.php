<?php
function defaultVal($i = 0) {
  echo "You passed ".$i."\n";
}

function addOne(&$i) {
  ++$i;
}

defaultVal();
$x = 1;
echo "initial value: ".$x."\n";
addOne($x);
echo "final value: ".$x."\n";
?>
