<?php
$conn = new mysqli("localhost", "root", "", "st_lab");
$sql = "DELETE FROM students WHERE roll_no=".$_GET["id"];
$conn->query($sql);

?>
<script>
  window.location.replace("/lab-6/q2.php");
</script>