from collections import deque

# 총 반복 횟수
n = int(input())
for _ in range(n):

    # 체스판의 크기
    I = int(input())

    # 현재 위치, 도착 위치
    Y, X = map(int, input().split())
    Y_D, X_D = map(int, input().split())

    visited = [[-1] * I for _ in range(I)]
    dx = (1, 1, 2, 2, -1, -1, -2, -2)
    dy = (-2, 2, -1, 1, -2, 2, -1, 1)

    que = deque()
    que.append([Y, X])
    visited[Y][X] = 0

    while(que):

        y, x = que.popleft()
        if(y == Y_D and x == X_D):
            print(visited[y][x])
            break

        for i in range(8):
            ny = y + dy[i]
            nx = x + dx[i]
            
            if(0 <= ny < I and 0 <= nx < I and visited[ny][nx] == -1):
                que.append([ny, nx])
                visited[ny][nx] = visited[y][x] + 1