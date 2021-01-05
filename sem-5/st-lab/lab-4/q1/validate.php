<?php
function valid_email($email)
{
  if (is_array($email) || is_numeric($email) || is_bool($email) || is_float($email) || is_file($email) || is_dir($email) || is_int($email))
    return false;

  $email = trim(strtolower($email));
  $pattern = '/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,3})$/';
  return (preg_match($pattern, $email) === 1);
}

$email = $_GET["email"];
if (valid_email($email)) {
  echo "Email is valid";
} else {
  echo "Email is invalid";
}

?>