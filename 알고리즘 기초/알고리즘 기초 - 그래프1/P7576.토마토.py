from collections import deque
M, N = map(int, input().split())
# M : 가로, N : 세로
graph = []
visited = [[0] * M for _ in range(N)]
for _ in range(N):
    graph.append(list(map(int, input().split())))

dx = (-1, 1, 0, 0)
dy = (0, 0, -1, 1)

que = deque()

    

for y in range(N):
    for x in range(M):
        if(graph[y][x] == 1 and visited[y][x] == 0):
            visited[y][x] = 1
            que.append([y, x])

while(que):
    _y, _x = que.popleft()
    for i in range(4):
        ny = _y + dy[i]
        nx = _x + dx[i]
        if(0 <= ny < N and 0 <= nx < M and visited[ny][nx] == 0 and graph[ny][nx] != -1):
            visited[ny][nx] = visited[_y][_x] + 1
            que.append([ny, nx])

result = max(map(max, visited)) - 1
for y in range(N):
    if(result == -1):
        break
    for x in range(M):
        if(graph[y][x] == 0 and visited[y][x] == 0):
            result = -1
            break

print(result)