<?php
setcookie("name", $_COOKIE["name"] . "123", time() + 60 * 60);

?>
<script>
  window.location.replace("/lab-5/q1.php");
</script>