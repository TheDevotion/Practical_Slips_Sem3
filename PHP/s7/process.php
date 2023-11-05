<?php

/*

Write a menu driven PHP program to perform the following operations on an
associative array:
i. Display the elements of an array along with the keys.
ii. Display the size of an array
iii. Delete an element from an array from the given index.

iv. Reverse the order of each element’s key-value pair.[Hint: use array_flip()]
v. Traverse the elements in an array in random order [[Hint: use shuffle()].

*/
if($_SERVER["REQUEST_METHOD"] == "POST")  {

	$choice = $_POST['choice'];
	$index = $_POST['index'];

	
		
	$arr = array(
		'a' => 'apple',
		'b' => 'ball',
		'c' => 'cat',
	);
	
	do {
	switch($choice) {
	
		case 1 :
			print_r($arr);
			break;
		case 2: 
			$count = count($arr);
			echo " Count = $count <br>";
			break;
		case 3:
			unset($arr[$index]);
			print_r($arr);
			break;

		case 4:
				print_r(array_flip($arr));
				break;

		case 5:
				shuffle($arr);
				print_r($arr);
				break;
		case 6: 
				echo"Exiting the program";
				exit;
				break;
		default: 
				echo" Invalid choice<br>";
				break;
            }
	
	// Ask for the next choice
        echo "<br><br>";
	echo" <pre>
		i. Display the elements of an array along with the keys.
		ii. Display the size of an array
		iii. Delete an element from an array from the given index.
		iv. Reverse the order of each element’s key-value pair.
		v. Traverse the elements in an array in random order 
		vi.exit.
	</pre> <br>";
        echo "Enter your choice: ";
        echo '<form action="process.php" method="post">';
        echo '<input type="number" name="choice" placeholder="Enter your choice">';
        echo '<input type="text" name="index" placeholder="Give index for option 3">';
        echo '<input type="submit" name="submit">';
        echo '</form>';

		

	}while(false);
	
}

?>