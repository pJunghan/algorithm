# def solution(n):
#     return f(n)

# def f(n):
#     if n == 0:
#         return 0
#     elif n == 1:
#         return 1
#     else:
#         return (f(n - 1) + f(n - 2)) % 1234567

def solution(n):
    # 초기값
    f0 = 0
    f1 = 1
    fn = 0

    for i in range(2, n + 1):
        fn = f0 + f1
        # f(n) = f(n - 1) + f(n - 2)
        f0 = f1
        f1 = fn

    return fn % 1234567
    # 시간 복잡도 O(n) 반복문