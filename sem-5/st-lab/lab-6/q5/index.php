<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Welcome</title>
  <style>
    body {
      margin: 15px 20%;
      font-family: sans-serif;
    }

    b {
      display: block;
    }

    .error {
      color: red;
    }

    .block {
      display: block;
      width: 270px;
      /* border: 1px solid #787878; */
      padding: 10px;
      margin: 10px;
    }
  </style>
</head>

<body>
  <h1>Welcome to MySpace!</h1>
  <h2>Signup:</h2>
  <form action="/lab-6/q5/login-user.php" method="post">
    <label class="block">
      <b>username: </b>
      <input type="text" name="username" required="true">
    </label>
    <label class="block">
      <b>password: </b>
      <input type="password" name="password" required="true">
    </label>
    <label class="block">
      <input type="submit" name="submit">
      <?php
      if (isset($_COOKIE["error"])) {
        echo "<p class='error'>" . $_COOKIE["error"] . "</p>";
      }
      ?>
    </label>
  </form>
  <p>
    New User?
    <a href="register.php">register</a>
  </p>
</body>

</html>