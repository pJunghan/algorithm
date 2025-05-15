""" 
굉장히 일반적인 BFS (최단거리, 게임)

 """

from collections import deque


dx = [-1, 1, 0, 0]  # 상, 하
dy = [0, 0, -1, 1]  # 좌, 우


# ------> y 행
# |
# |
# |
# |
# v  x 열

def solution(maps): # 메인 함수
    n = len(maps)         # 행
    m = len(maps[0])      # 열
    v = [[0]*m for _ in range(n)]  # 방문 여부 및 거리 저장 배열
    
    sx, sy = 0, 0         # 시작 
    ax, ay = n, m         # 도착 
    
    # BFS
    answer = BFS(v,maps,sx,sy,ax,ay,n,m)
    return answer


# BFS 함수
def BFS(v, graph, sx, sy, ax, ay, n, m): # 방문, 그래프, 시작 xy , 끝 xy , 행, 열
    que = deque()
    que.append([sx, sy])
    v[sx][sy] = 1  # 시작 지점 방문 처리 (1은 거리 1로도 사용됨)

    while que: # 큐안에 아무것도 없을때 까지
        x, y = que.popleft() 

        # 상하좌우 네 방향 탐색
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 도착 지점 도달 시 거리 반환
            if (nx, ny) == (ax-1, ay-1):
                return v[x][y] + 1

            # 범위 내 , 방문하지 않음 , 이동 가능한 경로가 1인 경우
            if 0 <= nx < n and 0 <= ny < m and v[nx][ny] == 0 and graph[nx][ny] == 1:
                que.append([nx, ny])
                v[nx][ny] = v[x][y] + 1  # 거리 갱신

    return -1  # 도달 불가능할 경우 


# 통과 (0.04ms, 9.11MB)
# 시간 복잡도 : O(n * m)