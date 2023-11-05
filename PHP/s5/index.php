<!doctype html>
<html>
<head>
	<title> occurance of string</title>
</head>
<body>


<!--

Write a PHP script for the following: Design a form to accept the details of 5 different
items, such as item code, item name, units sold, rate. Display the bill in the tabular
format. Use only 4 text boxes. (Hint : Use of explode function.)
-->

<form method="post" action="process.php">

<h1>Give items details for 5 products </h1><br>

<label for="itemCode" >itemCode</label><br>
<input type="text" id="itemCode" name="itemCode" required><br>

<label for="name" >item Name</label><br>
<input type="text" id="name" name="name" required><br>

<label for="unitsSold" >units sold</label><br>
<input type="text" id="unitsSold" name="unitsSold" required><br>

<label for="rate" >rate</label><br>
<input type="text" id="rate" name="rate" required><br>



<input type="submit" value="Submit">

</form>
</html>