<?php
$a = array(2, 6, 8, 12, 3, -5, 7);
$n = count($a);
sort($a);
echo "Largest Number: ".$a[$n - 1]."\n";
echo "Smallest Number: ".$a[0]."\n";
?>
