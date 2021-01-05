<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Document</title>
  <style>
    button {
      margin: 10px;
    }
  </style>
  <script>
    function set() {
      window.location.replace("/lab-5/q1-set.php");
    }

    function replace() {
      window.location.replace("/lab-5/q1-replace.php");
    }

    function append() {
      window.location.replace("/lab-5/q1-append.php");
    }
  </script>
</head>

<body>
  <button onclick="set()">Set Cookie</button>
  <button onclick="replace()">Replace Cookie</button>
  <button onclick="append()">Append Cookie</button>
  <?php
  if (isset($_COOKIE["name"])) {
    echo "<h1>Cookie set to: " . $_COOKIE["name"] . "</h1>";
  } else {
    echo "<h1>Cookie not set</h1>";
  }
  ?>
</body>

</html>