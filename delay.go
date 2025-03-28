package main
import "fmt"
import "time"
func number(){
	for i:=0;i<5;i++{
		time.delay(250*time.millisecond)
		fmt.Println("%d",i)
	}
}
func main(){
	go number()
	time.delay(3000*time.millisecond)
}