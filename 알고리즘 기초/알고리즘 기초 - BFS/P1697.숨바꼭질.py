from collections import deque

X, XD = map(int, input().split())

visited = [-1] * 100001
que = deque()

que.append(X)
visited[X] = 0

while(que):
    x = que.popleft()

    if(x == XD):
        print(visited[x])
        break
    for nx in [x-1, x+1, 2*x]:
        if(0 <= nx < 100001 and visited[nx] == -1):
            que.append(nx)
            visited[nx] = visited[x] + 1