<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width,
initial-scale=1.0">
  <meta http-equiv="X-UA-Compatible" content="ie=edge">
  <title>ST-3 | Q6</title>
</head>

<body>
  <h2>
    You have been logged off.
    </h2>
    Thankyou, 
    <?php
      session_start();
      echo " ".$_SESSION["name"];
      session_unset();
    ?>!
</body>