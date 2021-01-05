<?php
$username = $_COOKIE["username"];
$conn = new mysqli("localhost", "root", "", "st_lab");
$sql = "DELETE FROM `users` WHERE `users`.`username` = '" . $username . "';";
echo $sql;
$conn->query($sql);
header("location: logout.php");
die;
