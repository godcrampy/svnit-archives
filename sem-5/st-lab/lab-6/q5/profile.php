<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Profile</title>
  <style>
    body {
      margin: 15px 20%;
      font-family: sans-serif;
    }

    b {
      display: block;
    }

    .block {
      display: block;
      width: 270px;
      /* border: 1px solid #787878; */
      padding: 10px;
      margin: 10px;
    }

    .class {
      color: red;
    }
  </style>
</head>

<body>
  <?php
  if (!isset($_COOKIE["auth"])) {
    setcookie("error", "Signin first", time() + 2);
    header("location: index.php");
    die;
  }
  echo "<h1>Welcome " . $_COOKIE["username"] . "!</h1>";
  echo "<h2>Your Status " . $_COOKIE["status"] . "</h2>";
  ?>
  <form action="/lab-6/q5/set-status.php" method="post">
    <label class="block">
      <b>Status: </b>
      <input type="text" name="status" required="true">
    </label>
    <label class="block">
      <input type="submit" name="submit" value="Set Status">
    </label>
  </form>
  <?php
  if (isset($_COOKIE["error"])) {
    echo "<p class='error'>" . $_COOKIE["error"] . "</p>";
  }
  ?>

  </label>
  </form>
  <h2>What's up with people!</h2>
  <table>
    <tr>
      <th>Username</th>
      <th>Status</th>
    </tr>
    <?php

    $conn = new mysqli("localhost", "root", "", "st_lab");
    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }

    $sql = "SELECT * FROM users";
    $result = $conn->query($sql);


    if ($result->num_rows > 0) {
      // output data of each row
      while ($row = $result->fetch_assoc()) {
        echo "<tr>";
        echo "<td>" . $row["username"] . "</td>";
        echo "<td>" . $row["status"] . "</td>";
        echo "</tr>";
      }
    } else {
      echo "0 results";
    }
    $conn->close();

    ?>
  </table>

  <form action="/lab-6/q5/logout.php" method="post">
    <label class="block">
      <input type="submit" name="logout" value="Logout">
    </label>
  </form>
  <form action="/lab-6/q5/delete.php" method="post">
    <label class="block">
      <input type="submit" name="logout" value="Delete">
    </label>
  </form>
</body>

</html>