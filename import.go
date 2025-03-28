package main

import (
	"fmt"  // Importing the fmt package for formatted I/O
	"math" // Importing the math package for mathematical operations
)

func main() {
	// Using the fmt package to print a message
	fmt.Println("Demonstrating the use of import in Go!")

	// Using the math package to calculate the square root of a number
	number := 16.0
	result := math.Sqrt(number)
	fmt.Printf("The square root of %.2f is %.2f\n", number, result)
}
