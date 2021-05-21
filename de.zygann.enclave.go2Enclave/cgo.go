package main

/*
 #include "./App/App.h"
 #cgo CFLAGS: -I./App -I$SGX_SDK/include
 #cgo LDFLAGS: -L. -ltee
*/
import "C"

import (
	"fmt"
	//"os"
)

// go test
func test() {
	fmt.Printf("Hello Intel SGX")
}

func main() {
	//test()

	// fmt.Println("LD_LIBRARY_PATH:", os.Getenv("LD_LIBRARY_PATH"))

	C.goMain()
}
