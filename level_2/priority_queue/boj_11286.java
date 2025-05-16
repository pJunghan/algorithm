package level_2.priority_queue;

import java.util.*;
import java.io.*;

public class boj_11286 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>(){
            @Override
            public int compare(Integer a, Integer b){
                if(Math.abs(a) == Math.abs(b)){
                    return Integer.compare(a, b);
                }else{
                    return Integer.compare(Math.abs(a), Math.abs(b));
                }
            }
        });

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<N;i++){
            int x = Integer.parseInt(br.readLine());

            if(x == 0){
                if(pq.size() <= 0){
                    sb.append("0");
                    sb.append("\n");
                }else{
                    sb.append(pq.poll());
                    sb.append("\n");
                }
            }else{
                pq.add(x);
            }
        }
        
        System.out.println(sb.toString());
    }
}
