<?php
setcookie("name", "xyz", time() + 60 * 60);

?>
<script>
  window.location.replace("/lab-5/q1.php");
</script>