package level_3.priority_queue;

import java.util.*;
import java.io.*;

public class boj_13975 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        PriorityQueue<Long> pq;
        int T = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for(int t=0; t<T; t++){
            int K = Integer.parseInt(br.readLine());
            pq = new PriorityQueue<>();
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<K; i++){
                pq.offer(Long.parseLong(st.nextToken()));
            }

            long c1;
            long c2;
            long cnt = 0;

            while(pq.size() > 1){
                c1 = pq.poll();
                c2 = pq.poll();

                cnt += (c1+c2);

                pq.offer(c1+c2);
            }

            sb.append(cnt);
            sb.append("\n");
        }

        System.out.println(sb.toString());
    }
}
