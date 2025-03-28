package main
import "fmt"
func main(){
	age:=-14
	error:=fmt.Errorf("%d is neg \n age cant negative ",age)
	if age<0{
		fmt.Println(error)
	}else{
		fmt.Println("age %d ",age)

	}
}