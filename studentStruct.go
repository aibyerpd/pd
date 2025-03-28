package main
import "fmt"
type student struct{
	name string
	roll int
}
func(s *student)show(sroll int ,sname string){
	(*s).roll=sroll
	(*s).name=sname
}
func main(){
a:=student{ 
	name:"Aman",
    roll:13 ,
}

	fmt.Println("Student name is",a.name)
	fmt.Println("Student name is",a.roll)

	p:=&a

	p.show(2,"ram")
	fmt.Println("Student name is",a.name)
	fmt.Println("Student name is",a.roll)



}