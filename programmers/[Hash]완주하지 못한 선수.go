/**
 * [Hash] 완주하지 못한 선수
 * https://programmers.co.kr/learn/courses/30/lessons/42576
 */

package main

import "fmt"

func solution(participant, completion []string) string {
	var answer string
	// ㅇㅏ래의 경우 단순 변수 선언: 리터럴 초기화는 "map[Key타입]Value타입 { key:value }"
	//var participantMap, completionMap map[string]int
	// make의 경우, 초기화 상태임: 새로운 데이타를 추가하기 위해서는 "map변수[키] = 값"
	participantMap := make(map[string]int)
	completionMap := make(map[string]int)

	// key 이름기준: 지원자 수 체크
	for _, name := range participant {
		participantMap[name] += 1
	}
	// key 이름기준: 완주자 수 체크
	for _, name := range completion {
		completionMap[name] += 1
	}

	// 이름기준으로, 지원자 != 완주자 인 경우가 정답에 해당함
	for _, name := range participant {
		if participantMap[name] != completionMap[name] {
			answer = name
			break
		}
	}

	return answer
}

func main()  {
	// 코드 결과
	fmt.Printf("%v\n", solution([]string{"leo", "kiki", "eden"}, []string{"eden", "kiki"})) // leo
	fmt.Printf("%v\n", solution([]string{"marina", "josipa", "nikola", "vinko", "filipa"}, []string{"josipa", "filipa", "marina", "nikola"})) // vinko
	fmt.Printf("%v\n", solution([]string{"mislav", "stanko", "mislav", "ana"}, []string{"stanko", "ana", "mislav"})) // mislav
}
