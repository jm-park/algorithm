/**
 * [ 이분탐색 ]
 * 문제: 2805 나무자르기
 *
 * https://www.acmicpc.net/problem/2805
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

long long N, M, answer;
vector<long long> tree;

long long checkSum(int mid) {
    long long result = 0, size = tree.size();

    for(int i = 0; i < size; i++) {
        if(tree[i]-mid > 0)
            result += (tree[i]-mid);
    }

    return result;
}

void bst() {
    long long start = 0, end = tree[N-1], mid;

    while(end >= start) {
        mid = (start+end)/2;
        long long result = checkSum(mid);

        // 최대가 될 수 있는 값으로 설정
        if(result >= M) {
            answer = max(answer, mid);
        }

        if(result > M) {
            start = mid+1;
        } else if(result <= M) {
            end = mid-1;
        }

    }

}

int main() {

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        tree.push_back(x);
    }

    // 오름차순 정렬
    sort(tree.begin(), tree.end());

    // 이분탐색
    bst();

    cout << answer << endl;

    return 0;
}