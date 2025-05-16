package level_3.dp;

import java.io.*;
import java.util.*;

public class boj_17404 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());

        // 빨강, 초록, 파랑 순서
        int[][] RGB = new int[N][3];

        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            RGB[i][0] = Integer.parseInt(st.nextToken());
            RGB[i][1] = Integer.parseInt(st.nextToken());
            RGB[i][2] = Integer.parseInt(st.nextToken());
        }

        int[] colors = {0,1,2};
        
        int answer = 10000000;

        for(int color : colors){
            int[][] dp = new int[N][3];

            dp[0][0] = 10000000;
            dp[0][1] = 10000000;
            dp[0][2] = 10000000;

            dp[0][color] = RGB[0][color];

            for(int i=1; i<N; i++){
                dp[i][0] = findMin(dp[i-1][1], dp[i-1][2]) + RGB[i][0];
                dp[i][1] = findMin(dp[i-1][0], dp[i-1][2]) + RGB[i][1];
                dp[i][2] = findMin(dp[i-1][1], dp[i-1][0]) + RGB[i][2];
            }

            dp[N-1][color] = 10000000;

            int dpMin = findMin(dp[N-1][0], dp[N-1][1], dp[N-1][2]);
            answer = findMin(answer, dpMin);
        }

        System.out.println(answer);
        
    }
    
    public static int findMin(int a, int b){
        int min = a;

        if(b < min){
            min = b;
        }

        return min;
    }

    public static int findMin(int a, int b, int c){
        int min = a;

        if(b < min){
            min = b;
        }

        if(c < min){
            min = c;
        }

        return min;
    }
}
