package main

import (
	"fmt"
)

func findDisappearedNumbers(nums []int) []int {
	var answer []int
	size := len(nums)

	for i := 0; i < size; i++ {

		// 방문할 수 있는 숫자 탐색
		var tmp int
		if nums[i] > 0 {
			tmp = nums[i]
		} else {
			// X -1 경우:  이미 방문한 노드일 경우 음수처리가 되어있기 때문에 양수로 변경시킨다!
			tmp = nums[i]*-1
		}

		// 방문처리: 음수로 표기하면서 방문했음을 처리한다.
		// -1하는이유: 실제 size는 1~n 이지만, index 는 0 ~ n-1이기 때문에
		if nums[tmp-1] > 0 {
			nums[tmp-1] = nums[tmp-1]*-1
		}

	}

	// 정답 찾기
	for i := 0; i < size; i++ {

		// 양수: 한번도 방문하지못함 -> 숫자가 없었기 때문에 방문을 못한것
		if nums[i] > 0 {
			// +1 이유: 실제 size는 1~n 이지만, index 는 0 ~ n-1이기 때문에
			answer = append(answer, i+1)
		}
	}

	return answer
}

func main()  {

	// 코드 결과
	// Runtime: 52 ms, faster than 89.23% of Go online submissions for Find All Numbers Disappeared in an Array.
	// Memory Usage: 7 MB, less than 79.23% of Go online submissions for Find All Numbers Disappeared in an Array.

	nums := []int{4,3,2,7,8,2,3,1}
	fmt.Printf("%d\n", findDisappearedNumbers(nums))
}
