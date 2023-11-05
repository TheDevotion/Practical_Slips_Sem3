
<?php
/*
Write a PHP script for the following: Design a form to accept two strings. Compare
the two strings using both methods (= = operator &strcmp function). Append the
second string to the first string. Accept the position from the user; from where the
characters from the first string are reversed. (Use radio buttons) [25
M]
*/

 if($_SERVER["REQUEST_METHOD"] == "POST") {

	$string1 = $_POST['string1'];
	$string2 = $_POST['string2'];
	$position = $_POST['position'];

	function stringOperations($string1,$string2,$position) {
		
		echo"<h2> by == method: </h2>";
		if($string1 == $string2) {
			echo"Stirng 1 equal string 2";
		}else {
			echo"string1 not equal string2";
		}

		echo"<h2>  by strcmp method</h2>";
		$ans = strcmp($string1,$string2);

		if($ans == 0 ) {
			echo "equal";
		}elseif($ans < 0) {
			echo" str 1 smaller";
		}else {
			echo" str2 bigger";
		}

		echo "<h2> Append str2 to str1</h2>";
		
		$appendedString = $string1 . $string2;
		echo"appended string: $appendedString<br>";
		
		echo "<h2> Reverse from $position</h2>";
		
			$reversedString = strrev(substr($string1,$position));

		echo "$reversedString";

	}


	if(isset($_POST['submit'])) {
		
		stringOperations($string1,$string2,$position);
		
	}

}


?>