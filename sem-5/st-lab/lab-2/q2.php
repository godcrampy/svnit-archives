<?php
function armstrong_number($num) {
	$sl = strlen($num);
	$sum = 0;
	$num = (string)$num;
	for ($i = 0; $i < $sl; $i++) {
		$sum = $sum + pow((string)$num{$i},$sl);
	}
	if ((string)$sum == (string)$num) {
		echo $num."\n";
	}
}
echo "Armstrong Numbers among the first 500 numbers"."\n";
for($i = 1; $i <= 500; $i++) {
	armstrong_number($i);
}
?>
