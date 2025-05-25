from collections import deque

def solution(s):
    answer = 0
    s = deque(s)

    for _ in range(len(s)):
        stack = []
        for char in s:
            if stack:
                if stack[-1] == '[' and char == ']':
                    stack.pop()
                elif stack[-1] == '{' and char == '}':
                    stack.pop()
                elif stack[-1] == '(' and char == ')':
                    stack.pop()
                else:
                    stack.append(char)
            else:
                stack.append(char)

        if not stack:
            answer += 1

        s.rotate(-1)  # 왼쪽으로 한 칸 회전 (pop(0) + append 방식과 동일)

    return answer
