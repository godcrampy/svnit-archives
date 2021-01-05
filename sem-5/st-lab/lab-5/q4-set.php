<?php
setcookie("value", $_POST["value"], time() + 60 * 60);
?>
<script>
  window.location.replace("/lab-5/q4.php");
</script>