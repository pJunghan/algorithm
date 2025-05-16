package level_2.priority_queue;

import java.util.*;
import java.io.*;

public class boj_11279 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b){
                return Integer.compare(b, a);
            }
        });

        StringBuilder sb = new StringBuilder();

        for(int i=0;i<N;i++){
            int x = Integer.parseInt(br.readLine());

            if(x==0){
                if(pq.isEmpty()){
                    sb.append(0);
                    sb.append("\n");
                }else{
                    sb.append(pq.poll());
                    sb.append("\n");
                }
            }else{
                pq.offer(x);
            }
        }

        System.out.println(sb.toString());
    }
}
