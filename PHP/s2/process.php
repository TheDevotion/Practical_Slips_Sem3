<?php

	if($_SERVER["REQUEST_METHOD"] == "POST" ) {

		$str1 = $_POST['str1'];
		$str2 = $_POST['str2'];
		$replaceStr = $_POST['replaceStr']; 

		function stringOperations($str1,$str2,$replaceStr) {
		
			$total = 0;
	
			$first = strpos($str1, $str2);
			$last = strrpos($str1, $str2);
			$total = substr_count($str1,$str2);

			if($first !== false) {
				echo" First Occurance : Position: $first<br>";
			}else {
				echo" Small string not found in large string<br>";
			}
			if($last !== false) {
				echo" Last Occurance Position: $last<br>";
			}else {
				echo" Small string not found in large string<br>";
			}
			
			echo"<h3>Total number $str2 occurs in $str1 = $total</h3>";
		
			echo"<h3> Replaced string is: </h3>";

			$replacedString = str_replace($str2,$replaceStr,$str1);

			echo"<h3>$replacedString</h3><br>";

		
		}


		if(isset($_POST['submit'])) {
			stringOperations($str1, $str2,$replaceStr);
		}

}
	
	