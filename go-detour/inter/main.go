package main

import (
	"fmt"
	"os"
)

func main() {
	if len(os.Args) != 3 {
		return
	}

	str1:=os.Args[1]
	str2 := os.Args[2]

	seen:=make(map[rune]bool)
	res:=[]string{}

	for _,char1:= range str1{
		for _,char2:=range str2{
			// if !seen[char1] && !seen[char2]{
			// 	res = append(res, string(char1))
			// 	res = append(res, string(char2))
			// 	seen[char1] = true
			// 	seen[char2] = true
			if char1==char2 && !seen[char1]{
				res=append(res, string(char1))
				seen[char1]=true
			}

			}

		}
	for _,char:= range res{

		fmt.Print(char)
	}
	fmt.Println()

}
