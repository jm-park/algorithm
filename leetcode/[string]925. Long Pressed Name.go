package main

import (
	"fmt"
)

func isLongPressedName(name string, typed string) bool {
	answer := true
	idx := 0
	lth := len(name)
	for typeIdx, _ := range typed {

		// 마지막까지 다 도달한 경우는 탈출
		if idx == lth {
			if name[idx-1] != typed[typeIdx] {
				answer = false
			}
			break
		}

		if name[idx] == typed[typeIdx] {
			idx++
		} else if idx == 0 || name[idx-1] != typed[typeIdx] {
			answer = false
			break
		}
	}

	if idx != lth || name[lth-1] != typed[len(typed)-1] {
		answer = false
	}
	return answer
}

func main()  {
	// 코드 결과
	// Runtime: 0 ms, faster than 100.00% of Go online submissions for Long Pressed Name.
	// Memory Usage: 2 MB, less than 35.71% of Go online submissions for Long Pressed Name.
	fmt.Printf("%v\n", isLongPressedName("alex", "aaleex")) // true
	fmt.Printf("%v\n", isLongPressedName("saeed", "ssaaedd")) // false
	fmt.Printf("%v\n", isLongPressedName("leelee", "lleeelee")) // true
	fmt.Printf("%v\n", isLongPressedName("laiden", "laiden")) // true
	fmt.Printf("%v\n", isLongPressedName("vtkgn", "vttkgnn")) // true
	fmt.Printf("%v\n", isLongPressedName("a", "b")) // false
	fmt.Printf("%v\n", isLongPressedName("alex", "aaleexa")) // false
	fmt.Printf("%v\n", isLongPressedName("bdad", "bbbd")) // false
}
