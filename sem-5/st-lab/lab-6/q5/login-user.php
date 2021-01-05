<?php
$username = $_POST["username"];
$password = $_POST["password"];

echo $username;
echo $password;

$conn = new mysqli("localhost", "root", "", "st_lab");
// Check connection
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}
//check if username is taken
$sql = "SELECT * FROM `users` WHERE username='" . $username . "' AND password='" . $password . "'";
$result = $conn->query($sql);

if ($result->num_rows == 0) {
  setcookie("error", "Username or Password wrong", time() + 2);
  header("location: index.php");
  die;
}


$row = $result->fetch_assoc();
$status = $row["status"];
$email = $row["email"];
echo $status;

setcookie("auth", "true", time() + 60 * 60 * 24);
setcookie("username", $username, time() + 60 * 60 * 24);
setcookie("status", $status, time() + 60 * 60 * 24);
setcookie("email", $email, time() + 60 * 60 * 24);
header("location: profile.php");
die;
