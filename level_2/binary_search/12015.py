import sys

input = sys.stdin.readline

n = int(input())  # 수열의 길이 입력
cases = list(map(int, input().split()))  # 수열 입력

lis = [0]  # LIS 배열 초기화 (편의를 위해 맨 앞에 0을 넣음)

for case in cases:
    if lis[-1] < case:
        # 현재 숫자가 LIS의 마지막보다 크면 그대로 추가 (수열 연장)
        lis.append(case)
    else:
        # 그렇지 않으면, 현재 숫자가 들어갈 자리를 이진 탐색으로 찾음
        left = 0
        right = len(lis)

        while left < right:
            mid = (left + right) // 2
            if lis[mid] < case:
                left = mid + 1
            else:
                right = mid

        # 찾은 위치에 현재 숫자를 넣어서 LIS 배열 유지
        lis[right] = case

# lis 배열에는 실제 LIS는 아니고, 길이만 맞는 구성 요소들이 들어 있음
# 따라서 길이에서 맨 앞의 0을 제외해야 함
print(len(lis) - 1)


# from bisect import bisect_left  # 이진 탐색 지원 (정렬된 리스트에서 삽입 위치 찾기)
#
# lis = []
#
# for num in cases:
#     idx = bisect_left(lis, num)
#     # lis에서 num이 들어갈 위치를 찾는다.
#
#     if idx == len(lis):
#         # num이 lis의 모든 원소보다 크므로, 새로운 증가 수열 확장 가능
#         lis.append(num)
#     else:
#         # 해당 위치에 교체 (값을 작게 유지하면 더 많은 원소 수용 가능)
#         lis[idx] = num
#
# # lis에는 실제 LIS는 아님. 단지 길이만 유지됨.
# print(len(lis))