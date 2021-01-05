<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>q2</title>
</head>

<body>
  <?php
  setcookie("name", "xyz", time() + 60 * 60 * 24 * 2);
  echo "<h1>Cookie name set to: " . $_COOKIE["name"] . " for 2 days</h1>"
  ?>
</body>

</html>