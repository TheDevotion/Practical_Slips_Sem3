<?php

interface shape {
	public function area();
	public function volume();
}

define("PI",3.142);

class cylinder implements shape {
	
	private $radius;
	private $height;

	public function __construct($radius,$height) {
		$this -> radius = $radius;
		$this -> height = $height;
	}

	public function area() {
		return  2 * PI * $this->radius * ($this->radius + $this->height);
	}

	public function volume() {
		return PI * $this->radius *$this->radius * $this->height;
	}
}

	$Cyl = new cylinder(5,10);
	
	echo " Area = ". $Cyl -> area() ." <br> ";
	echo " Volume = ".$Cyl ->volume()."<br>";



?>