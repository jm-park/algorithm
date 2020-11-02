/**
 * [ 이분탐색 ]
 * 문제: 2805 나무 자르기
 *
 * https://www.acmicpc.net/problem/2805
 */
import java.util.*;
import java.io.*;

public class Main {

    // (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
    private static long N, M, answer = 0;
    private static ArrayList<Long> tree = new ArrayList<>();

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");

        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);

        // 다음라인 입력받기
        line = br.readLine().split(" ");
        for(int i = 0; i < N; i++) {
            long num = Long.parseLong(line[i]);
            tree.add(num);
        }

        // 오름차순 정렬
        Collections.sort(tree);

        // 이분탐색
        bst();

        System.out.println(answer);
    }

    private static void bst() {
        long start = 0, end = tree.get(tree.size()-1), mid;

        while(end >= start) {
            mid = (start+end) / 2;

            long result = checkSum(mid);

            // answer 저장
            if(result >= M) {
                answer = mid > answer ? mid : answer;
            }

            if(result > M) {
                start = mid+1;
            } else if(result <= M) {
                end = mid-1;
            }
        }
    }

    private static long checkSum(long mid) {
        long result = 0;
        for(long value : tree) {
            if(value - mid > 0) {
                result += value - mid;
            }
        }

        return result;
    }
}
