<?php
// check if auth
$status = $_POST["status"];
$username = $_COOKIE["username"];

echo $status;
echo $username;
// update cookie
setcookie("status", $status, time() + 60 * 60 * 24);
// update db
$conn = new mysqli("localhost", "root", "", "st_lab");

$sql = "UPDATE `users` SET `status` = '" . $status . "' WHERE `users`.`username` = '" . $username . "';";
echo $sql;
$conn->query($sql);
header("location: profile.php");
die;
