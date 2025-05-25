def solution(numbers):
    answer = []
    # 처음부터 마지막 전까지만
    for i in range(0, len(numbers)):
        # 첫번쨰부터 마지막까지
        for j in range(i + 1, len(numbers)):
            answer.append(numbers[i] + numbers[j])
    # 배열에 전부 더한 후 정렬 + set으로 중복제거
    return sorted(set(answer))