<?php

$email = $_GET["email"];
echo "You entered: ".$email."<br>";

$email = filter_var($email, FILTER_SANITIZE_EMAIL);
echo "Sanitized email: ".$email."<br>";

// Validate e-mail
if (filter_var($email, FILTER_VALIDATE_EMAIL)) {
    echo $email." is a valid email address<br>";
} else {
    echo $email." is an invalid email address<br>";
}

?>