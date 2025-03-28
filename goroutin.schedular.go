package main
import "fmt"
import "time"
func name(){
arr:=[4]string {"rohit","virat","jadega","pandya"}
for i:=0;i<=3;i++{
	time.Sleep(150*time.Millisecond)
	fmt.Printf("%s",arr[i])

       }
}
func id(){
	arr:=[4]int {100,200,300,400}
	for j:=0;j<=3;j++{
		time.Sleep(500*time.Millisecond)
		fmt.Printf("%d",arr[j])
	}
}
func main(){
	fmt.Println("main go routin start")
	go name()
	go id()
	time.Sleep(3000*time.Millisecond)
	fmt.Println("main go routin end")

}