<?php
function fibonacci($num) {
	$a = 1;
	$b = 1;
	$sum = $a + $b;
	for($i = 1; $i <= $num; $i++) {
		echo $a."\n";
		$a = $b;
		$b = $sum;
		$sum = $a + $b;
	}
}
$n = 10;
fibonacci($n);
?>