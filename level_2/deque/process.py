from collections import deque


# 문제 이해하는데 오래 걸림 -> 당연히 1 이 우선순위가 제일 높은 건줄.. 앎 
# 예를 들어 프로세스 4개 [A, B, C, D]가 순서대로 실행 대기 큐에 들어있고, 
# 우선순위가 [2, 1, 3, 2]라면 [C, D, A, B] 순으로 실행하게 됩니다.

# A -> 2 , B -> 1 , C -> 3  D-> 2
# A  [B C D] C가 우선순위가 더 높기 때문에 [B C D A]
# B  [C D A] C가 우선순위가 더 높기 때문에 [C D A B]
# C  [D A B] C의 우선순위가 제일 높음 -> C 아웃 
# D  [A B]   우선순위 큰거 없음 아웃 -> D
# A  [B]     우선순위 큰거 없음 아웃 -> A
# B          마지막 아웃 -> B

def solution(priorities, location):
    answer = 0

    # 각 문서에 알파벳 태그 붙이기 (a, b, c, ...) <- 이부분은 검색 찬스 
    alp = deque([chr(code) for code in range(97,97+ len(priorities))])

    priorities = deque(priorities) # 우선순위 큐 생성
    ans = alp[location] # 내가 찾고자 하는 문서 태그

    
    while priorities : 
        num = priorities.popleft() # 큐(선입선출) 제일 처음에 있는 문서 빼옴
        a_num = alp.popleft()  # 알파벳 순서대로 
           
        
        if any(num < p for p in priorities): # any 함수(조건에 맞는 문만 Ture) 사용 : 남은 문서중에 높은 우선 순위가 있다면
            priorities.append(num) # 맨뒤로 보내기
            alp.append(a_num) # 알파벳도 같이 이동

        else:
            answer += 1  # 문서 출력
            if ans == a_num:
                return answer #내가 찾던 문서면 종료
                


    return answer