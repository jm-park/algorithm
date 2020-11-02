/**
 * [ 우선순위큐 ]
 * 문제: 1202 보석도둑
 *
 * https://www.acmicpc.net/problem/1202
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

int N, K;
long long answer;
vector<pair<int,int>> jew;
vector<int> bags;

int main() {

    //  (1 ≤ N, K ≤ 300,000)
    cin >> N >> K;

    // 각 보석N 의 정보 무게Mi와 가격Vi
    for(int i = 0; i < N; i++) {
        int w, p;
        cin >> w >> p;
        jew.push_back({w,p}); // first: 무게, w:가격
    }
    // 보석 무게기준 오름차순정렬
    sort(jew.begin(), jew.end());

    // 가방K 에 담을 수 있는 최대 무게 Ci
    for(int i = 0; i < K; i++) {
        long long bag;
        cin >> bag;
        bags.push_back(bag);
    }

    // 가방무게 내림차순 정렬
    sort(bags.begin(), bags.end());

    // MAX Heap
    priority_queue<long long> pq;
    int idx = 0; // 보석 index
    for(int k = 0; k < K; k++) {

        /**
         * [logic]
         * 해당 가방에 담을 수 있는 모든 보석을 pq에 담아준다.
         *
         * [중요포인트]
         * 어차피 보석&가방 모두 무게 작은순으로 "오름차순" 되어있음
         *
         * 그중에서 가장 비싼것 우선으로 가방에 담기 때문에, 이전 무게들 또한 상관없이 계속 pq에 담아있게됨(왜냐, bag 벡터는 갈수록 커지기때문)
         */
        while(idx < N && jew[idx].first <= bags[k]) {
            pq.push(jew[idx++].second);
        }

        if(!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    // 보석 가격의 합의 최댓값
    cout << answer << endl;

    return 0;
}