<?php
unset($_COOKIE["auth"]);
setcookie("auth", null, -1);
header("location: index.php");
die;
