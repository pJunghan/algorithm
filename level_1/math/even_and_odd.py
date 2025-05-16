def solution(num):
    # 2로 나눠지면 짝수 아니면 홀수
    if num % 2 == 0:
        return 'Even'
    else:
        return 'Odd'
    # 시간복잡도 O(1)