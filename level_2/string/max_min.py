def solution(s):
    # 문자열 int형으로 쪼개놓기
    answer = list(map(int,s.split(' ')))
    # max min 값 각각 넣은 후 f'' 사용해서 포맷팅함
    return f'{min(answer)} {max(answer)}'
    # 시간복잡도 O(n)