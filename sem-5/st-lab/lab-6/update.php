<?php
$conn = new mysqli("localhost", "root", "", "st_lab");

$sql = "UPDATE `students` SET `email` = '" . $_GET['email'] . "', `name` = '" . $_GET['name'] . "', `cgpa` = '" . $_GET['cgpa'] . "' WHERE `students`.`roll_no` = " . $_GET["roll_no"] . ";";
echo $sql;
$conn->query($sql);

?>
<script>
  window.location.replace("/lab-6/q4.php");
</script>