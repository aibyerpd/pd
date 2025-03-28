package main
import (
	"fmt"
    "time"
)
func main(){
	fmt.Println("Welcome to main function")
	 func(){
		fmt.Println("Welcome inside anonymous")
		time.Sleep(300*time.Millisecond)
		fmt.Println("aaaaa")
	}()
}