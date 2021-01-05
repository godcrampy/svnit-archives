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
    <?php session_start();
    $name = $_GET["name"];
    $_SESSION["name"] = $name;
    echo "Welcome ".$name;
    ?>
  </h2>
  <form action="logout.php" method="get">
    <input type="submit" name="logout" value="Logout">
  </form>
</body>

</html>