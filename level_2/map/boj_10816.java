package level_2.map;

import java.util.*;
import java.io.*;


public class boj_10816 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        
        Map<Integer, Integer> map = new HashMap<>();
        
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            int key =  Integer.parseInt(st.nextToken());
            map.put(key, map.getOrDefault(key,0)+1);
        }
        
        int M = Integer.parseInt(br.readLine());
        
        StringBuilder sb = new StringBuilder();
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<M;i++){
            int key = Integer.parseInt(st.nextToken());
            if(map.containsKey(key)){
                sb.append(map.get(key));
            }else{
                sb.append(0);
            }
            sb.append(" ");
        }

        System.out.println(sb.toString());
    }

}