/**
 * [ 다익스트라 ]
 * 문제: 11779 최소비용 구하기 2
 *
 * https://www.acmicpc.net/problem/11779
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, answer;
vector<int> answerCity;
vector<pair<int,int>> bus[1005];

int dijkstra(int dept, int dest) {

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, dept}); // first: 비용, 맨마지막: 도착지
    int cityCost[1005];

    // 초기화: 최대값으로 채워둔다.
    fill_n(cityCost, N+1, 987654321);
    cityCost[dept] = 0;

    while(!pq.empty()) {
        vector<int> cityInfo = pq.top();
        pq.pop();
        int city = cityInfo[cityInfo.size()-1], cost = cityInfo[0];

        for(pair<int,int> next: bus[city]) {
            if(cityCost[next.second] > cost+next.first) {
                cityCost[next.second] = cost+next.first;

                vector<int> newCity = cityInfo;
                newCity[0] = cityCost[next.second];
                newCity.push_back(next.second); // 맨마지막에 장소를 넣음

                pq.push(newCity);

                // 도착지인 경우는 엎어쓴다.
                if(next.second == dest) {
                    answerCity = newCity;
                }
            }
        }

    }

    return cityCost[dest];
}

int main() {

    // 도시의 개수 n(1≤n≤1,000), 버스의 개수 m(1≤m≤100,000)
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        // 출발 도시의 번호, 도착지의 도시 번호, 버스 비용( 0이상, 100,000보다 작은)
        int x, y, cost;
        cin >> x >> y >> cost;

        bus[x].push_back({cost, y}); // first: 비용, second: 도착지
    }


    // 시작, 도착
    int start, end;
    cin >> start >> end;

    // 최소 비용
    answer = dijkstra(start,end);

    // 모든 행성을 터널로 연결하는데 필요한 최소 비용, 도시 수, 도시 경로
    int size = answerCity.size();
    cout << answer << endl << size-1 << endl;
    for(int i = 1; i < size; i++) {
        cout << answerCity[i] << " ";
    }
    cout << endl;

    return 0;
}