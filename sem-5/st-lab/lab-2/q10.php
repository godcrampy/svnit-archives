<?php
$n = 6;
for($i = 1; $i <= $n; $i++) {
	for($s = 1; $s <= $n - $i; $s++) {
		echo " ";
	}
	for($o = 1; $o <= $i; $o++) {
		echo $o;
	}
	for($r = $i - 1; $r >= 1; $r--) {
		echo $r;
	}
	echo "\n";
}
?>
