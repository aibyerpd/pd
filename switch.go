package main
import "fmt"
func main(){
	var value interface{}="3"
	switch t:=value.(type){
	case int64:
		fmt.Println("Type is int",t)
	case float32:
		fmt.Println("Type is float",t)
	case string:
		fmt.Println("Type is string",t)
	case nil:
		fmt.Println("Type is nill",t)
	default:
		fmt.Println("no record found ",t)
	}
}