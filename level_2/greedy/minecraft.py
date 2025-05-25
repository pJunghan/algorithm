def solution(picks, minerals):
    from math import ceil

    total_picks = sum(picks)  # 사용할 수 있는 곡괭이 총 개수
    max_mineable = total_picks * 5  # 캘 수 있는 최대 광물 수
    minerals = minerals[:max_mineable]  # 곡괭이로 캘 수 있는 만큼만 자르기

    # 5개씩 묶어 광물 덩어리 그룹 생성
    groups = []
    for i in range(0, len(minerals), 5):
        chunk = minerals[i:i+5]
        dia = chunk.count('diamond')
        iron = chunk.count('iron')
        stone = chunk.count('stone')
        groups.append([dia, iron, stone])

    # 가장 가치 있는 광물 그룹부터 정렬 (다이아 > 철 > 돌 순)
    groups.sort(key=lambda x: (-x[0], -x[1], -x[2]))

    fatigue = 0
    for group in groups:
        dia, iron, stone = group

        # 곡괭이 우선순위: 다이아 → 철 → 돌
        if picks[0] > 0:  # 다이아 곡괭이
            picks[0] -= 1
            fatigue += dia + iron + stone
        elif picks[1] > 0:  # 철 곡괭이
            picks[1] -= 1
            fatigue += (5 * dia) + iron + stone
        elif picks[2] > 0:  # 돌 곡괭이
            picks[2] -= 1
            fatigue += (25 * dia) + (5 * iron) + stone
        else:
            break  # 사용할 곡괭이가 없다면 종료

    return fatigue
