package level_3.priority_queue;

import java.util.*;
import java.io.*;

public class boj_1715 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int i=0;i<N;i++){
            pq.offer(Integer.parseInt(br.readLine()));
        }

        int cnt = 0;
        while(pq.size() >= 2){
            int c1 = pq.poll();
            int c2 = pq.poll();

            cnt += (c1 + c2);

            pq.offer(c1 + c2);
        }

        System.out.println(cnt);
    }
}
