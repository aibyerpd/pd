package main
import "fmt"
type autherdetail interface{
	details()
}
type autherarticle interface{
	articles()
}

type finddetails interface{
	autherarticle
	autherdetail
}
type auther struct{
	aname string
	branch string
	aid int 
	particle int 
	tarticle int 
}

func (a auther) details(){
	fmt.Println("authe name is",a.aname)
	fmt.Println("authe id is",a.aid)
	fmt.Println("authe branch is",a.branch)

}

func (a auther) articles(){
	fmt.Println("total article is",a.tarticle)
	fmt.Println("pending article is",a.tarticle-a.particle)
}
func main(){
	a:=auther{
		aname:"ram",
	branch:"abc",
	aid:11, 
	particle:2, 
	tarticle:4 ,
	}

	var f finddetails=a
	
	f.articles()
	f.details()
}