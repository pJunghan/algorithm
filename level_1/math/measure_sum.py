def solution(n):
    answer = 0
    # 초기값
    for i in range(1,n + 1):
    # 1부터 자기자신까지 나눠지는 수가 약수임
        if n % i == 0:
    # 나눠지는 수면 더하기
            answer += i
    return answer
    # 시간복잡도 O(n)