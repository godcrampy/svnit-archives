<?php
function is_prime($num) {
	$j = 0;
	for($i = 1; $i <= $num; $i++) {
		if (!($num % $i)) {
			$j++;
		}
	}
	if ($j <= 2) {
		echo $num."\n";
	}
}
$n = 100;
for($i = 2; $i <= $n; $i++) {
	is_prime($i);
}
?>
