def solution(n, words):
    answer = []  # 정답 리스트 
    ans_word = [] # 사람들이 말한 단어
    num = 0 # words 카운트 리스트 
    cnt = 1 # 전체 횟수 리스트 
    pas = "" # 전역처리
    
        
        
    for a in range((len(words)//n+1)):
        
        for i in range(n):
            j = num + i
            
            
            if j == len(words): # 만약에 word전체를 다돌았는데 없다면 종료해라
                answer.append([0,0]) 
                return answer[0]
            
            nw = words[j] # 현재 단어 , 지역처리
            

            if words[j] in ans_word :  # 같은 단어 찾기        
                answer.append([i+1,cnt])
                return answer[0]
            
            if len(pas) != 0 and nw[0] != pas[-1]: # 규칙 위반
                answer.append([i+1,cnt]) #1 을 더하는 이유는 사람번호는 1부터 시작
                return answer[0]
            
            
            ans_word.append(words[j]) # 전체 말한 리스트에 단어 넣기 
            pas = words[j] # 과거 단어  

        
        num += n  # words를 돌기 위한 
        cnt += 1  # 바퀴수 카운트

    return answer 


#아무래도 코드가 너무.. 난잡하다 순서를 잘못하면 삑사리가 잘난다, 변수가 크면 메모리가 차이가 날지도?

###############################################################################################
#생각 해보니까 set 쓰면 될것 같아서 

def solution(n, words):
    used = set()
    nw_word = words[0] # 처음 오류 방지
    used.add(nw_word) # 제일 처음 단어 

    for i in range(1, len(words)):
        curr_word = words[i]

        # 같은 단어가 다시 나오거나, 끝말잇기 규칙 위반
        if curr_word in used or curr_word[0] != nw_word[-1]:
            return [(i % n) + 1, (i // n) + 1] # i 전체 돌아가는 횟수 , n 사람수  1을 더하는 이유는 사람번호는 1부터 시작

        used.add(curr_word) # 집합에 현재 끝말잇기 단어 넣기
        nw_word = curr_word

    return [0, 0]

#1 시간복잡도 O(n^2)
#1 시간복잡도 O(n)

#1 통과 (0.01ms, 9.07MB)
#2 통과 (0.02ms, 9.21MB)