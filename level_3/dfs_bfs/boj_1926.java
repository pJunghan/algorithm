package level_3.dfs_bfs;

import java.util.*;
import java.io.*;

public class boj_1926 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        boolean[][] visited = new boolean[n][m];
        int[][] paper = new int[n][m];

        Queue<Integer[]> q1 = new ArrayDeque<>();
        Queue<Integer[]> q2 = new ArrayDeque<>();

        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                paper[i][j] = Integer.parseInt(st.nextToken());
                if(paper[i][j] == 0){
                    visited[i][j] = true;
                }else{
                    q1.offer(new Integer[]{i,j});
                }
            }
        }

        int[] di = new int[]{1,0,-1,0};
        int[] dj = new int[]{0,1,0,-1};

        int cntPaper = 0;
        int maxPaper = 0;

        while(!q1.isEmpty()){
            q2.clear();
            int cnt = 0;

            Integer[] start = q1.poll();

            if(!visited[start[0]][start[1]]){
                q2.offer(start);
                visited[start[0]][start[1]] = true;
                cnt++;
            }else{
                continue;
            }


            while(!q2.isEmpty()){
                Integer[] curr = q2.poll();

                int ci = curr[0];
                int cj = curr[1];

                for(int k=0;k<4;k++){
                    int ni = ci + di[k];
                    int nj = cj + dj[k];
                    if(0 <= ni && ni <n && 0 <= nj && nj < m){
                        if(!visited[ni][nj]){
                            visited[ni][nj] = true;
                            q2.offer(new Integer[]{ni,nj});
                            cnt++;
                        }
                    }
                }

            }

            maxPaper = max(maxPaper, cnt);
            cntPaper++;
        }

        System.out.println(cntPaper);
        System.out.println(maxPaper);
    }

    public static int max(int a, int b){
        int max = a;
        
        if(a < b){
            max = b;
        }

        return max;
    }
}
