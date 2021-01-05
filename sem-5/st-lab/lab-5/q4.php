<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>q4</title>
</head>

<body>
  <form action="/lab-5/q4-set.php" method="post">
    <input type="text" name="value" />
    <input type="submit" />
  </form>
  <?php
  if (isset($_COOKIE["value"])) {
    echo "<h1>Cookie set to: " . $_COOKIE["value"] . "</h1>";
  } else {
    echo "<h1>Cookie not set</h1>";
  }
  ?>
</body>

</html>