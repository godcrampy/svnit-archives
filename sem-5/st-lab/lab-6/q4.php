<style>
  inline {
    display: inline;
  }
</style>
<table border="1">
  <tr>
    <th>Roll No.</th>
    <th>Name</th>
    <th>email</th>
    <th>CGPA</th>
    <th>Action</th>
  </tr>

  <?php
  $conn = new mysqli("localhost", "root", "", "st_lab");
  // Check connection
  if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
  }
  echo "Connected successfully";

  $sql = "SELECT * FROM students";
  $result = $conn->query($sql);


  if ($result->num_rows > 0) {
    // output data of each row
    while ($row = $result->fetch_assoc()) {
      echo "<tr><form action='update.php' method='get'>";
      echo "<td>" . $row["roll_no"] . "<input name='roll_no' type='hidden' value='" . $row["roll_no"] . "'/></td>";
      echo "<td><input name='name' value='" . $row["name"] . "'/></td>";
      echo "<td><input name='email' value='" . $row["email"] . "'/></td>";
      echo "<td><input name='cgpa' value='" . $row["cgpa"] . "'/></td>";
      echo "<td><input type='submit' value='Update'/></td>";
      echo "</form></tr>";
    }
  } else {
    echo "0 results";
  }
  $conn->close();
  ?>
</table>