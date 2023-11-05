<?php

/*
Write a PHP script for the following: Design a form to accept the details of 5 different
items, such as item code, item name, units sold, rate. Display the bill in the tabular
format. Use only 4 text boxes. (Hint : Use of explode function.)

*/


if($_SERVER["REQUEST_METHOD"] == "POST") {
	
	$itemCode = $_POST['itemCode'];
	$name = $_POST['name'];
	$unitsSold = $_POST['unitsSold'];
	$rate = $_POST['rate'];

	$itemarr = explode(" ", $itemCode);
	$namearr = explode(" ", $name);
	$unitsSoldarr = explode(" ", $unitsSold);
	$ratearr = explode(" ", $rate);

	echo"<h2>Bill Details</h2><br>";

	echo"<table border=1 cellpadding=0 cellspacing=0>";
	echo"<tr>
			<th>Item Code</th>
			<th>Item name</th>
			<th>Units Sold</th>
			<th>Rate</th>
			<th>total</th>
		</tr>";

	for($i=0; $i<5; $i++) {
		echo"<tr>
				<td>$itemarr[$i]</td>
				<td>$namearr[$i]</td>
				<td>$unitsSoldarr[$i]</td>
				<td>$ratearr[$i]</td>
				<td>". ($unitsSoldarr[$i] * $ratearr[$i])."</td>
		</tr>";
	}
	echo"</table>";
	
	if(isset($_POST['submit'])) {
		
		displayDetails($itemCode, $name, $unitsSold, $rate);
	}
}
	