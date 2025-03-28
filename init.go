package main
import "fmt"
func init(){
	fmt.Println("this is first init");
}
func init(){
	fmt.Println("this is second init");
}
func init(){
	fmt.Println("this is third init");
}
func init(){
	fmt.Println("this is fourth init");
}
func main(){
	fmt.Println("the main method call at the end");
}