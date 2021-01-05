<?php
$name = $_POST["name"];
$username = $_POST["username"];
$password = $_POST["password"];
$email = $_POST["email"];

$conn = new mysqli("localhost", "root", "", "st_lab");
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
//check if username is taken
$sql = "SELECT * FROM `users` WHERE username='" . $username . "'";
$result = $conn->query($sql);

if ($result->num_rows != 0) {

  setcookie("error", "Username is already taken", time() + 2);
  header("location: register.php");
  die;
}

$sql = "INSERT INTO `users` (`username`, `password`, `email`, `status`) VALUES ('" . $username . "', '" . $password . "', '" . $email . "', 'I am using MYSpace!');";
echo $sql;
$conn->query($sql);
header("location: index.php");

die;
