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
function palindrome($num) {
	$res = reverse($num);
	if ($res === $num) {
		echo $num." is a Palindrome.\n";
	} else {
		echo $num." is not a Palindrome.\n";
	}
}
$n1 = 14;
$n2 = 141;
palindrome($n1);
palindrome($n2);
?>