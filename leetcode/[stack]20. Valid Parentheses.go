package main

import "fmt"

func isValid(s string) bool {
	answer := true
	var stack []int32
	lth := len(s)

	// 어차피 홀수면 불가
	if lth%2 == 1 {
		return false
	}

	for _, ch := range s {
		if ch == '(' || ch == '[' || ch == '{' {
			stack = append(stack, ch)
		} else if len(stack) == 0 {
			answer = false
			break
		} else {
			lastVal := stack[len(stack)-1]

			switch ch {
			case ')':
				if lastVal != '(' {
					answer = false
				}
			case ']':
				if lastVal != '[' {
					answer = false
				}
			case '}':
				if lastVal != '{' {
					answer = false
				}
			default:
				answer = false
			}

			if !answer {
				break
			} else {
				stack = stack[:len(stack)-1]
			}
		}
	}

	if len(stack) > 0 {
		answer = false
	}
	return answer
}

func main()  {
	fmt.Printf("%v\n", isValid("){"))
}
