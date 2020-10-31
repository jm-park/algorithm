/**
 * [ 그리디 ]
 * 문제: 1202 보석도둑
 *
 * https://www.acmicpc.net/problem/1202
 */
import java.util.*;
import java.io.*;

public class Main {

    private static int N, K, answer = 0;
    private static int coins[] = new int[10];

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for(int i = 0; i < N; i++) {
            coins[i] = Integer.parseInt(br.readLine());
        }

        // 동전 선택 부분
        while(K > 0) {
            greedy();
        }

        System.out.println(answer);
    }

    private static void greedy() {

        // 1. 동전 선택
        int coin = choidCoinIdx(K);

        // 2. 동전 사용 갯수 선택
        int cnt = 1;
        while(true) {
            if(coins[coin]*cnt >= K) {
                if(coins[coin]*cnt > K) {
                    cnt--;
                }
                break;
            }

            cnt++;
        }

        // 사용횟수 증가
        answer += cnt;

        // 3. 총 남은 금액 정산
        K -= coins[coin]*cnt;
    }

    private static int choidCoinIdx(int value) {
        int idx = 0;

        for(;idx < N; idx++) {
            if(coins[idx] >= value) {
                break;
            }
        }

        if(idx == N || coins[idx] > value) idx--;

        return idx;
    }
}
