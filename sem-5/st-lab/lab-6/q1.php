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
  echo "Connected successfully";

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