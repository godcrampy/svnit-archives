<?php
$conn = new mysqli("localhost", "root", "", "st_lab");
$q1 = "SELECT COUNT(*) FROM students";
$c = $conn->query($q1)->fetch_array()[0] + 1;
$sql = "INSERT INTO `students` (`roll_no`, `name`, `email`, `cgpa`) VALUES ('" . $c. "', '" . $_GET['name'] . "', '" . $_GET['email'] . "', '" . $_GET['cgpa'] . "');";
echo $sql;
$conn->query($sql);

?>
<script>
  window.location.replace("/lab-6/q3.php");
</script>