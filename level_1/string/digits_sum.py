def solution(n):
    answer = 0
    # 초기값
    for i in str(n):
    # 문자열 순회
        answer += int(i)
    # 문자값마다 정수로 형변환 후 더하기
    return answer
    # 시간복잡도 O(n)