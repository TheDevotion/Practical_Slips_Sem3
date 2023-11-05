<!doctype html>
<html>
<head>
	<title>Count vowels and palindrome</title>
</head>

<body>
<form method="post" action="process.php">
	<h1>Give  String:</h1>
	<br><br>

	<label for="str1">Input string:</label><br>
	<input type="text" id="str1" name="str1" required><br>

	<h2>Operations on that string:</h2>

	<label for="countVowels">Count Total Number of Vowels in given string.</label>
	<input type="radio" id="countVowels" name="operation" value="countVowels" required><br>
	<label for="palindrome">Check if the string is palindrome or not</label>

	<input type="radio" id="palindrome" name="operation" value="palindrome" required><br>
	
	<input type="submit" value="Submit">
	</form>
</body>
</html>