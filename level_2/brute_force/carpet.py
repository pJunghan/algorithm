def solution(brown, yellow):
    answer = []
    all_color = brown + yellow # 전체 타일 수 
    print(all_color)
    
    u = sosu(all_color) # 전체 넓이의 약수쌍

            
    for a, b in u:
         if yellow == (a-2) * (b-2): #노란색 영역
                answer.append([a,b])
    
    
    return answer[0]


def sosu(n):
    sa = []
    for i in range(1,n+1):
        if n%i == 0: # n의 약수일 때
            a = i
            b = n//i
            if a >= b :
                sa.append([a,b]) 
            
    return sa
            

#  https://school.programmers.co.kr/learn/courses/30/lessons/42842
    