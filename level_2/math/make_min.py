def solution(A,B):
    answer = 0
    A.sort()
    B.sort(reverse=True)
    for i in range(len(A)):
        # 배열의 크기는 같음
        answer += (A[i] * B[i])
        # 예시에 1 * 4 + 2 * 3 처럼 하나는 내림차순 다른 하나는 오름차순으로 하는 것이 최솟값을 만듬
        # 시간복잡도 O(n log n)임! 정렬이 O(n log n)이므로
    return answer