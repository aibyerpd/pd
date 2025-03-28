package main
import "fmt"
func main(){
	age:=-14
	error:=fmt.Errorf("%d no is neg ",age)
	if age<0{
		fmt.Println(error)
	}else{
		fmt.Println("age correct")
		
	}
}