package level_3.priority_queue;

import java.io.*;
import java.util.*;

public class boj_2109 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        
        StringTokenizer st;

        PriorityQueue<Node> nodes = new PriorityQueue<>();
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());

            int p = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            nodes.add(new Node(p,d));
        }

        boolean[] days = new boolean[10000];
        
        Node node;
        int money = 0;
        while(!nodes.isEmpty()){
            node = nodes.poll();

            boolean lec = false;

            for(int i=node.d-1;i>=0;i--){
                if(!days[i]){
                    days[i] = true;
                    lec = true;
                    break;
                }
            }

            if(lec){
                money += node.p;
            }

        }

        System.out.println(money);
    }
    
    public static class Node implements Comparable<Node>{

        int p;
        int d;

        public Node(int p, int d){
            this.p = p;
            this.d = d;
        }

        @Override
        public int compareTo(Node o) {
            return Integer.compare(o.p, this.p);
        }

    }
}
