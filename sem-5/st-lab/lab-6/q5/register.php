<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Register</title>
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
  <h1>Join MySpace!</h1>
  <form action="/lab-6/q5/register-user.php" method="post">
    <label class="block">
      <b>username: </b>
      <input type="text" name="username" required="true">
    </label>
    <label class="block">
      <b>name: </b>
      <input type="text" name="name" required="true">
    </label>
    <label class="block">
      <b>email: </b>
      <input type="text" name="email" required="true">
    </label>
    <label class="block">
      <b>password: </b>
      <input type="password" name="password" required="true">
    </label>
    <label class="block">
      <input type="submit" name="submit">
    </label>
  </form>
  <?php
  if (isset($_COOKIE["error"])) {
    echo "<p class='error'>" . $_COOKIE["error"] . "</p>";
  }
  ?>
</body>

</html>