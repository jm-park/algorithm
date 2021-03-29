/**
 * [string] 핸드폰 번호 가리기
 * https://programmers.co.kr/learn/courses/30/lessons/12948
 */

package main

import "fmt"

func solution(phone_number string) string {
	lth := len(phone_number)
	var answer string
	for i := 0; i < lth-4; i++ {
		answer += "*"
	}
	answer += phone_number[lth-4:]

	return answer
}

func main()  {
	// 코드 결과
	fmt.Printf("%v\n", solution("01033334444")) // *******4444
	fmt.Printf("%v\n", solution("027778888")) // *****8888
}
