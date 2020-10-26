#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue< int, vector<int>, greater<int> > pq;

	for (int i = scoville.size() - 1; i>-1; i--) pq.push(scoville[i]);

	while (true) {
		if (pq.top() >= K) return answer;
		else if (pq.size() == 1) return -1;
		else {
			int min1 = pq.top(); pq.pop();
			int min2 = pq.top(); pq.pop();
			pq.push(min1 + min2 * 2);
			answer++;
		}
	}
}