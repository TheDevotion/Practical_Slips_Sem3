

<html>
<head>
    <title>String Comparison</title>
</head>
<body>

<!--
Write a PHP script for the following: Design a form to accept two strings. Compare
the two strings using both methods (= = operator &strcmp function). Append the
second string to the first string. Accept the position from the user; from where the
characters from the first string are reversed. (Use radio buttons) [25
M]

-->
<center>	
    <h1>String Comparison</h1>

    <form action="process.php" method="post">
	
	<fieldset>

        <input type="text" name="string1" placeholder="Enter the first string">
        <input type="text" name="string2" placeholder="Enter the second string">

        <h2>Select the position from where the characters from the first string are reversed:</h2>

        <input type="radio" name="position" value="0" checked> Beginning
        <input type="radio" name="position" value="-1"> End
        <input type="radio" name="position" value="5"> Middle

        <input type="submit" name="submit" value="Compare">
	</fieldset>
	</center>
    </form>

</body>
</html>