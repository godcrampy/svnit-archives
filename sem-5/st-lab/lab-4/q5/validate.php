<?php
$keywords = array("Computer Engineering", "Electrical
Engineering", "Electronic Engineering", "Applied Mathematics");
$flag = false;
$name = $_POST['Name'];
$age = $_POST['Age'];
$email = $_POST['Email'];
$phone = $_POST['Phone'];
$dept = $_POST['Department'];
if (
  empty($name) || empty($age) || empty($email) || empty($phone)
  || empty($dept)
) {
  echo "Each field is required to be filled.<br>";
  $flag = true;
}
if ($age < 18) {
  echo "Age must be 18 or more to register for the
college.<br>";
  $flag = true;
}
if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
  echo $email . " is an invalid email address.<br>";
  $flag = true;
}
if (strlen((string)$phone) < 10 || strlen((string)$phone) > 10) {
  echo "Phone must contain only 10 digits.<br>";
  $flag = true;
}
foreach ($keywords as $index) {
  if ($dept != $index) {
    $flag = true;
  } else {
    $flag = false;
    break;
  }
}
if ($flag) {
  echo " We don't have this department in our college.<br>";
}
if (!$flag) {
  echo "<b>Name:</b> " . $name . "<br>";
  echo "<b>Age:</b> " . $age . "<br>";
  echo "<b>Email:</b> " . $email . "<br>";
  echo "<b>Phone:</b> " . $phone . "<br>";
  echo "<b>Department:</b> " . $dept . "<br>";
}
?>
