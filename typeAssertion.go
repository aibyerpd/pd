package main
import "fmt"
func main(){
	var t interface{}=2
	k,ok:=t.(int)
	if ok{
		fmt.Println("Success",k)
	}
	v,ok:=t.(float32)
	if ok{
		fmt.Println(v)
	}else
	{
		fmt.Println("faile without panicking")
	}
}