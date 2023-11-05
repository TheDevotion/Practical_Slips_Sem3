<?php

/*

 Write a menu driven PHP program to perform the following operations on associative
arrays:
a) Sort the array by values (changing the keys) in ascending, descending order.
b) Also sort the array by values without changing the keys.
c) Filter the odd elements from an array.
d) Sort the different arrays at a glance using single function.
e) Merge the given arrays.
f) Find the Union, intersection& set difference of two arrays
*/
if($_SERVER["REQUEST_METHOD"] == "POST")  {

	$choice = $_POST['choice'];
	$arr1= array(
		'a' => 5,
		'b' => 2,
		'c' => 1
	);
		$arr2= array(
		'e' => 1,
		'f' => 4,
		'g' => 2
	);
	
	do {
	switch($choice) {
	
		case 1 :
			echo"<br>ascending:<br>";
			sort($arr1);
			sort($arr2);
			print_r($arr1);
			print_r($arr2);

			echo"<br>Decending:<br>";
			rsort($arr1);
			rsort($arr2);
			print_r($arr1);
			print_r($arr2);
			
			break;
		case 2: 
			echo"<br>ascending:<br>";
			asort($arr1);
			asort($arr2);
			print_r($arr1);
			print_r($arr2);

			echo"<br>Decending:<br>";
			arsort($arr1);
			arsort($arr2);
			print_r($arr1);
			print_r($arr2);
			
			break;
		case 3:	
				echo " Odd values in array 1 are : <br>";
				$odd = array();
				foreach( $arr1 as $key => $value) {
						if($value %2 !== 0 ) {
							$odd[] = $value;
						}
				}
				print_r($odd);
				break;
			

		case 4:
				function sortArrays(...$arrays) {
					$result = array();
					foreach ($arrays as $arr ) {
						asort($arr);
						$result[] = $arr;
					}
					return $result;
				}
				echo" Sorted arrays: <br>";
				print_r(sortArrays($arr1,$arr2));
				break;

		case 5:
				$mergerArray = array_merge($arr1,$arr2);
				echo"Merger array:<br>";
				print_r($mergerArray);
				break;
		case 6: 
				$union = array_merge($arr1,$arr2);
				$intersection = array_intersect($arr1,$arr2);
				$difference = array_diff($arr1,$arr2);
			
				print_r($union);
				echo"<br>";

				print_r($intersection);
				echo"<br>";

				print_r($difference);
				echo"<br>";
				break;
				
		case 7: 
				echo"Exiting";
				exit;
				break;
		default: 
				echo" Invalid choice<br>";
				break;
            }
	
	// Ask for the next choice
        echo "<br><br>";
	echo" <pre>
		a) Sort the array by values (changing the keys) in ascending, descending order.
b) Also sort the array by values without changing the keys.
c) Filter the odd elements from an array.
d) Sort the different arrays at a glance using single function.
e) Merge the given arrays.
f) Find the Union, intersection& set difference of two arrays
7.exit
	</pre> <br>";
        echo "Enter your choice: ";
        echo '<form action="process.php" method="post">';
        echo '<input type="number" name="choice" placeholder="Enter your choice">';
       
        echo '<input type="submit" name="submit">';
        echo '</form>';

		

	}while(false);
	
}

?>