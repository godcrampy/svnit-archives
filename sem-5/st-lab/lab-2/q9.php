<?php
function reverse($n) {
	$r = 0;
	while ($n > 0) {
		$r = $r * 10;
		$r = $r + $n % 10;
		$n = (int)($n / 10);
	}
	return $r;
}
$n = 1478;
echo "Reverse of ".$n." is ".reverse($n)."\n";
?>