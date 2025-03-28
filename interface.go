package main
import "fmt"
type circle struct{
 rad float32
}
type rect struct{
	height float32
	lenght float32
}
type shape interface{
	area() float32
	perimeter() float32
}
func (c circle) area()float32{
	return 3.14*c.rad*c.rad
}
func (c circle) perimeter()float32{
	return 2*3.14*c.rad
}
func (r rect) area()float32{
	return r.lenght*r.height
}
func (r rect) perimeter()float32{
	return 2*r.lenght+2*r.height
}

func main(){
	c:=circle{rad:4.27}
	r:=rect{lenght:33,
	height:12.3,
        }
		fmt.Println("area of rectange is ",r.area())
		fmt.Println("area of circle is ",c.area())
		fmt.Println("peri of circle is ",c.perimeter())
		fmt.Println("peri of rect is ",c.perimeter())
}