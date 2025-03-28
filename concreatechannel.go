package main

import (
	"fmt"
)

func main() {
	// Create a channel to communicate between goroutines
	messageChannel := make(chan string)

	// Goroutine to send a message
	go func() {
		message := "Hello from the sender!"
		messageChannel <- message // Sending operation
	}()

	// Receive the message from the channel
	receivedMessage := <-messageChannel // Receiving operation
	fmt.Println("Received message:", receivedMessage)
}
