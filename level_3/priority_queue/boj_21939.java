package level_3.priority_queue;

import java.util.*;
import java.io.*;

public class boj_21939 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        
        int[] pList = new int[100001];

        PriorityQueue<Problem> pq = new PriorityQueue<>();
        PriorityQueue<Problem2> pq2 = new PriorityQueue<>();

        int no;
        int diff;
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            no = Integer.parseInt(st.nextToken());
            diff = Integer.parseInt(st.nextToken());

            pList[no] = diff;

            pq.add(new Problem(diff, no));
            pq2.add(new Problem2(diff, no));
        }

        int M = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();

        for(int i=0; i<M; i++){
            st = new StringTokenizer(br.readLine());

            String command = st.nextToken();

            if(command.equals("add")){
                no = Integer.parseInt(st.nextToken());
                diff = Integer.parseInt(st.nextToken());

                pList[no] = diff;

                pq.add(new Problem(diff, no));
                pq2.add(new Problem2(diff, no));
            }else if(command.equals("recommend")){
                int c = Integer.parseInt(st.nextToken());

                if(c == 1){
                    while(pList[pq.peek().no] != pq.peek().diff){
                        pq.poll();
                    }
                    sb.append(pq.peek().no);
                    sb.append("\n");
                }else{
                    while(pList[pq2.peek().no] != pq2.peek().diff){
                        pq2.poll();
                    }
                    sb.append(pq2.peek().no);
                    sb.append("\n");
                }
            }else{
                int sp = Integer.parseInt(st.nextToken());
                pList[sp] = 0;
            }
        }
        
        System.out.println(sb.toString());

    }

    public static class Problem implements Comparable<Problem>{
        int diff;
        int no;

        public Problem(int diff, int no){
            this.diff = diff;
            this.no = no;
        }

        @Override
        public int compareTo(Problem o) {
            if(this.diff == o.diff){
                return Integer.compare(o.no, this.no);
            }else{
                return Integer.compare(o.diff, this.diff);
            }
        }
    }

    public static class Problem2 implements Comparable<Problem2>{
        int diff;
        int no;

        public Problem2(int diff, int no){
            this.diff = diff;
            this.no = no;
        }

        @Override
        public int compareTo(Problem2 o) {
            if(this.diff == o.diff){
                return Integer.compare(this.no, o.no);
            }else{
                return Integer.compare(this.diff, o.diff);
            }
        }
    }
}
