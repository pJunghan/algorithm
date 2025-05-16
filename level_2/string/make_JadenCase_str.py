def solution(s):
    answer = s.split(' ')
    # 공백으로 쪼개기
    word = ''
    for i in answer:
    # 배열 순회
        if i:
        # 단어라면
            word += i[0].upper() + i[1:].lower() + ' '
            # 첫글자 대문자, 그 이후 소문자 + 띄어쓰기
        else:
            word += ' '
        # 아니면 그냥 띄어쓰기
    return word[:-1]
    # word += ' '로 마지막에 붙은 공백 제거하고 출력

    # return " ".join([word.capitalize() for word in s.split(" ")])
    # 이건 답을 보다가 이런 풀이도 있다고 해서 적어봤어요

    # 시간복잡도 O(n) 반복문