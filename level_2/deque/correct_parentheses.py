from collections import deque

def solution(s):
    st = deque()
    for i in s:
    # 문자열 반복
        if i == '(':
        # 여는 괄호면 추가하기
            st.append(i)
        elif i == ')' and len(st) != 0:
        # 닫는 괄호고 스택이 비어있는게 아니면 언더플로우가 아니니 내보내도됨
            st.pop()
        elif i == ')' and len(st) == 0:
        #만약 비어있으면 언더플로우니 정지
            return False
            break

    if len(st) == 0:
    # 반복이 끝난 상태에서 닫는 괄호랑 여는괄호 갯수가 맞으면
        return True
    else:
    # 아니면
        return False
    # 시간복잡도 O(n) 문자열 순회 반복문 때문