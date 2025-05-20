from collections import deque

# 참고 문제 : 올바른 괄호 https://school.programmers.co.kr/learn/courses/30/lessons/12909 

def solution(s):
    answer = -1
    ss = deque(s)
    
    
    for i in range(len(s)): # 총 s 길이만큼 돌리기
        a = rotation(ss)
        if a == True :  # true 인거 숫자 세기
            answer += 1 
        
        ss.append(ss.popleft())  # 제일 앞에 문자열빼서 뒤로 넣기 
        

    return answer+1



def rotation (lis):
    
    ans = []
    # pair = {')': '(', ']': '[', '}': '{'}
    
    if lis[0] == "]" or lis[0] == ")" or lis[0] == ")":
        return False
    
    
    
    for i in lis:
        
        # if i == "(" or i == "[" or i == "{":
        #     ans.append(i)
            
        if i == ")" or i == "]" or i == "}": 
            # if not ans or ans[-1] != pair[i]:   # ans에 없는 경우 ),},] 로 시작하거나 쌍이 없는 경우
#                 return False

            if len(ans) == 0:
                return False
            
            # if not ans:   # len보다 not을 쓰는게 배열이 길어지면 유리한듯 여기서 2배가량 차이남 
            #     return False
            
            if i == ")" and ans[-1] != "(":
                return False
            if i == "]" and ans[-1] != "[":
                return False 
            if i == "}" and ans[-1] != "{":
                return False

            
            ans.pop()
    
    if len(ans) != 0:
        return False
    
    return True


# 배열로 풀었을때 시간복잡도 : 통통과 (14.14ms, 9.27MB)
# 딕셔너리로 풀었을 때 시간복잡도 :  통과 (10.59ms, 9.23MB) 많이 차이나면 30% 정도 차이남
            