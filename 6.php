<?php

// Define variables
$string1 = '';
$string2 = '';
$position = 0;

// Check if the form has been submitted
if (isset($_POST['submit'])) {

    // Get the form data
    $string1 = $_POST['string1'];
    $string2 = $_POST['string2'];
    $position = $_POST['position'];

    // Compare the two strings using the == operator
    if ($string1 == $string2) {
        echo 'The two strings are equal.';
    } else {
        echo 'The two strings are not equal.';
    }

    // Compare the two strings using the strcmp function
    $comparisonResult = strcmp($string1, $string2);
    if ($comparisonResult == 0) {
        echo '<br>The two strings are equal.';
    } elseif ($comparisonResult < 0) {
        echo '<br>The first string is less than the second string.';
    } else {
        echo '<br>The first string is greater than the second string.';
    }

    // Append the second string to the first string
    $string1 .= $string2;

    // Reverse the characters from the first string from the specified position
    $reversedString = strrev(substr($string1, $position));

    // Display the results
    echo '<br>The first string with the second string appended is: ' . $string1;
    echo '<br>The first string with the characters reversed from position ' . $position . ' is: ' . $reversedString;
}

?>

<html>
<head>
    <title>String Comparison</title>
</head>
<body>

    <h1>String Comparison</h1>

    <form action="" method="post">	
	<fieldset style="center">

        <input type="text" name="string1" placeholder="Enter the first string">
        <input type="text" name="string2" placeholder="Enter the second string">

        <h2>Select the position from where the characters from the first string are reversed:</h2>

        <input type="radio" name="position" value="0" checked> Beginning
        <input type="radio" name="position" value="-1"> End
        <input type="radio" name="position" value="5"> Middle

        <input type="submit" name="submit" value="Compare">
	</fieldset>
    </form>

</body>
</html>
