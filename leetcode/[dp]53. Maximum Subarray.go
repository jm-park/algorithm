package main

import (
	"fmt"
)

func maxSubArray(nums []int) int {
	lth := len(nums)
	var dp [30005]int

	// 초기화
	dp[0] = nums[0]
	answer := nums[0]

	for i := 1; i < lth; i++ {
		if dp[i-1]+nums[i] > nums[i] {
			dp[i] = dp[i-1]+nums[i]
		} else {
			dp[i] = nums[i]
		}

		// max 값 찾기
		if answer < dp[i] {
			answer = dp[i]
		}
	}

	return answer
}

func main()  {

	// 코드 결과
	// Runtime: 4 ms, faster than 97.27% of Go online submissions for Maximum Subarray.
	// Memory Usage: 3.7 MB, less than 5.34% of Go online submissions for Maximum Subarray.
	
	nums := []int{-2,1,-3,4,-1,2,1,-5,4}
	fmt.Printf("%d\n", maxSubArray(nums))
}
