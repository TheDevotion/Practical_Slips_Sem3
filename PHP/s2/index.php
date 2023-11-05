<!doctype html>
<html>
<head>
	<title> occurance of string</title>
</head>
<body>


<!--

Write a PHP script for the following: Design a form to accept two strings from the
user. Find the first occurrence and the last occurrence of the small string in the large
string. Also count the total number of occurrences of small string in the large string.
Provide a text box to accept a string, which will replace the small string in the large
string. (Use built-in functions

-->

<form method="post" action="process.php">

<h1>Give two Strings</h1><br>

<label for="str1" >String 1:</label><br>
<input type="text" id="str1" name="str1"required><br>

<label for="str2" >String 2:</label><br>
<input type="text" id="str2" name="str2" required>

<h2>Give a string you want to replace string 2 with inside the large string</h2><br>
<input type="text" name="replaceStr" id="replaceStr"></br>  

<input type="submit" name="submit" value="Submit">

</form>
</html>