<?php
	
	if($_SERVER["REQUEST_METHOD"] == "POST") {
		$str1 = $_POST['str1'];

		function countVowels($str1) {
		
			$vowels = array("a", "e", "i", "o", "u");
			$str = strtolower($str1);
			$count = [];

			foreach($vowels as $val) {
				$count[$val] = substr_count($str,$val);
			}
			
			echo "Total number of Vowels in $str1 :" . array_sum($count) . "<br>";
			echo"Count of each vowel:<br>";
			foreach($count as $vowels => $x) {
				echo"$vowels = $x<br>";
			}
		}

		function isPalindrome($str1) {
			
			$len = strlen($str1);
		
			for($i=0; $i < $len /2; $i++) {
				
				if($str1[$i] !== $str1[$len -$i - 1]) {
				
					return false;
				}
			}
			return true;
		}
		
		$operation = $_POST['operation'];

		if($operation === "countVowels") {
			
			countVowels($str1);
		}
		if($operation === "palindrome") {
			
			$ans = isPalindrome($str1);
			
			if($ans) {
				echo"Given String is a palindrome<br>";
			}
			else {
				echo "Given string is not a palindrome<br>";
			}
		}
	}
?>
		
				
						