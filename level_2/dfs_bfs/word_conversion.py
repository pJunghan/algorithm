from collections import deque

def solution(begin, target, words):
    answer = 0
    answer = BFS(begin, target, words)  # BFS 호출 

    return answer



def BFS(begin, target, words):
    que = deque()
    que.append([begin,0]) # 시작 단어와 현재 변환 횟수


    v = [0] * len(words) # 방문 여부 표시
    v[0] = 0
    ans = 0
    
    while que:
        now,count = que.popleft()  # 현재 단어와 변환 횟수

        if now == target: # 목표 단어 도달 시 반환
            return count
        
        for i in range(len(words)): # 아직 방문하지 않았고, 한 글자만 다른 단어면
            right = change(words[i], now)

            if right == 1 and v[i] == 0 : # 한글자만 다르고 방문하지 않았다면
                que.append([words[i],count+1]) # 큐에 추가
                v[i] = 1 # 방문 표시 
                
    return 0 # 반환할 수 없는 경우 
            
    
    
def change(w,t):  # 두단어가 한글자만 다른지 확인 하는 함수
    num = 0
    for i in range(len(t)):
        if w[i] != t[i]:
            num += 1
                        
    if num == 1:
        return 1
    else: 
        return 0
    

#통과 (0.01ms, 9.42MB)
#시간복잡도 O(N^2) or O(N^2 * M) // M이 너무 작아서 괜찮음