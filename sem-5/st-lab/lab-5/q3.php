<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>q3</title>
</head>

<body>
  <?php
  if (!isset($_COOKIE["count"])) {
    setcookie("count", 1, time() + 60 * 60 * 24 * 2);
  } else {
    setcookie("count", $_COOKIE["count"] + 1, time() + 60 * 60 * 24 * 2);
  }
  echo "<h1>Cookie count is set to: " . $_COOKIE["count"] . "</h1>"
  ?>
</body>

</html>