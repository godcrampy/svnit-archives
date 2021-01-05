<?php
$a = array(45, 46, 47, 48);
echo "Accessing Index:\n";
echo $a[0]."\n";
echo $a[count($a) - 1]."\n";
echo "For Loop:\n";
for($i = 0; $i < count($a); ++$i) {
  echo $i.": ".$a[$i]."\n";
}
echo "For Each Loop:\n";
foreach($a as $i) {
  echo $i."\n";
}
?>