from collections import deque

X, XD = map(int, input().split())

visited = [-1] * 100001
lastnode = [-1] * 100001
que = deque()

que.append(X)
visited[X] = 0

while(que):
    x = que.popleft()

    if(x == XD):
        break
    for nx in [2*x, x-1, x+1]:
        if(0 <= nx < 100001 and visited[nx] == -1):
            que.append(nx)
            visited[nx] = visited[x] + 1
            lastnode[nx] = x

if(X == XD):
    print(0)
    print(X)


else:
    result = [XD]
    lastX = lastnode[XD]
    result.append(lastX)

    while(lastnode[lastX] != -1):
        lastX = lastnode[lastX]
        result.append(lastX)

    result.reverse()
    print(len(result)-1)
    for i in result:
        print(i, end = " ")
    print()