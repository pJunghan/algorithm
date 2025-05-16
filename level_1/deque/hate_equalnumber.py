from collections import deque

def solution(arr):
    st = deque()
    # 파이썬은 스택에서도 데큐를 씀
    st.append(arr[0])
    # 초기값
    for i in range(1, len(arr)):

        if st[-1] != arr[i]:
        # 맨 위의 값과 다르면 추가
            st.append(arr[i])

    answer = []
    # 스택 값 리스트로 변환하기 위해 사용
    for i in st:
        answer.append(i)

    return answer
    #시간 복잡도 O(n)