# def solution(brown, yellow):
# 근의 공식 활용 (높이, 넓이 공식 각각으로 식 두개 만들고 변수 두개 존재하니까 이차방정식 -> 근의공식)
#     x = (brown + 4 + ((brown + 4) ** 2 - 16 * (brown + yellow)) ** 0.5) / 4
#     y = (brown + yellow) / x

#     return [x, y]

def solution(brown, yellow):
    total = brown + yellow

    for height in range(3, total // 2 + 1):  # 세로는 최소 3부터
        if total % height == 0:  # 나누어 떨어져야 함
            width = total // height
            if width < height:
                continue  # 가로 ≥ 세로 조건
            # 내부 영역이 yellow와 같은지 확인
            if (width - 2) * (height - 2) == yellow:
                return [width, height]

# 시간복잡도 O(n)