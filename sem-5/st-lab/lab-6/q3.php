<!DOCTYPE html>
<html>

<head>
  <title>Form</title>
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
      border: 1px solid #787878;
      padding: 10px;
      margin: 10px;
    }
  </style>
</head>

<body>
  <h1>Add New Student</h1>
  <form method="get" action="add.php">
    <label class="block">
      <b>Name: </b>
      <input type="text" name="name" required="true">
    </label>
    <label class="block">
      <b>Email: </b>
      <input type="email" name="email" required="true">
    </label>
    <label class="block">
      <b>CGPA: </b>
      <input type="number" name="cgpa" step="0.01" required="true">
    </label>
    <label class="block">
      <input type="submit" name="submit">
    </label>
  </form>

  <table border="1">
    <tr>
      <th>Roll No.</th>
      <th>Name</th>
      <th>email</th>
      <th>CGPA</th>
    </tr>


    <?php
    $conn = new mysqli("localhost", "root", "", "st_lab");
    // Check connection
    if ($conn->connect_error) {
      die("Connection failed: " . $conn->connect_error);
    }

    $sql = "SELECT * FROM students";
    $result = $conn->query($sql);


    if ($result->num_rows > 0) {
      // output data of each row
      while ($row = $result->fetch_assoc()) {
        echo "<tr>";
        echo "<td>" . $row["roll_no"] . "</td>";
        echo "<td>" . $row["name"] . "</td>";
        echo "<td>" . $row["email"] . "</td>";
        echo "<td>" . $row["cgpa"] . "</td>";
        echo "</tr>";
      }
    } else {
      echo "0 results";
    }
    $conn->close();
    ?>
  </table>

</body>

</html>