<?php
$lang = $_GET["lang"];
$info = "";
switch ($lang) {
  case 'php':
    $info = 'PHP is a general-purpose scripting language that is especially suited to<br>
    web development. It was originally created by Danish-Canadian programmer Rasmus <br>
    Lerdorf in 1994; the PHP reference implementation is now produced by The PHP Group';
    break;

  case 'java':
    $info = 'Java is a class-based, object-oriented programming language that is designed<br>
    to have as few implementation dependencies as possible. It is a general-purpose <br>
    programming language intended to let application developers write once, run anywhere<br>
    (WORA),[17] meaning that compiled Java code can run on all platforms that support <br>
    Java without the need for recompilation.[18] Java applications are typically compiled <br>
    to bytecode that can run on any Java virtual machine (JVM) regardless of the underlying <br>
    computer architecture.';
  break;
  case 'c++':
    $info = 'C++ is a general-purpose programming language created by Bjarne Stroustrup as an <br>
    extension of the C programming language, or "C with Classes". The language has expanded <br>
    significantly over time, and modern C++ now has object-oriented, generic, and functional features<br>
    in addition to facilities for low-level memory manipulation.';
  break;
  default:
    $info = 'Error: Language not  found!';
    break;
}

echo "<h1>" . $lang . "</h1>";
echo "<p>" . $info . "</p>";

?>