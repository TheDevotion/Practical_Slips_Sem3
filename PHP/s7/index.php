

<html>
<head>
    <title>Menu Driven Program</title>
</head>
<body>

<!--
Write a menu driven PHP program to perform the following operations on an
associative array:
i. Display the elements of an array along with the keys.
ii. Display the size of an array
iii. Delete an element from an array from the given index.
iv. Reverse the order of each element’s key-value pair.[Hint: use array_flip()]
v. Traverse the elements in an array in random order [[Hint: use shuffle()].

-->
<center>	
    <h1>Menu driven</h1>

    <form action="process.php" method="post">
	
	<fieldset>
	<pre>
		i. Display the elements of an array along with the keys.
		ii. Display the size of an array
		iii. Delete an element from an array from the given index.
		iv. Reverse the order of each element’s key-value pair.
		v. Traverse the elements in an array in random order 
		vi.exit.
	</pre>

        <input type="number" name="choice" placeholder="Enter your choice">
	<input type="text" name="index" placeholder="Give key to delete">
        

        <input type="submit" name="submit">
	</fieldset>
	</center>
    </form>

</body>
</html>