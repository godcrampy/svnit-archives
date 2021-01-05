<?php
setcookie("name", "abc", time() + 60 * 60);

?>
<script>
  window.location.replace("/lab-5/q1.php");
</script>