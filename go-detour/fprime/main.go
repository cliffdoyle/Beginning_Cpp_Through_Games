package main

import (
	"fmt"
	"os"
	"strconv"
)



func isPrime(n int)bool{
	if n <= 1 {
		return false
	}

	for i:=2;i*i<=n;i++{
		if n % i==0{
			return false 
		}
	}
	return true
}

func main(){

	if len(os.Args) !=2{
		return
	}

	arg1,_:=strconv.Atoi(os.Args[1])

	res :=[]int{}

	for i:=2;i<=arg1;i++{
	for arg1 % i == 0 && isPrime(i) {
			res = append(res, i)
			arg1 /= i
		}
	}

	for i,val:= range res{
		if i > 0{

			fmt.Print("*")
			
		}
		fmt.Print(val)
}

	fmt.Println()
	}
// 		if arg1 % i ==0 && isPrime(i){
// 			res=append(res, i)
// 	}

// for _,val:= range res{
// 	fmt.Print('*')
// 	fmt.Print(val)
// }

