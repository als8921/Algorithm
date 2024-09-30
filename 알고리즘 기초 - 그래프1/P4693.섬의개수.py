while(1):
    w, h = map(int, input().split())
    if(w == 0 and h == 0):
        break

    graph = []
    visited = [[0] * w for _ in range(h)]

    for i in range(h):
        graph.append(list(map(int, input().split())))

    dx = (-1, -1, -1, 0, 0, 1, 1, 1)
    dy = (-1, 0, 1, -1, 1, -1, 0, 1)

    def bfs(y, x):
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]

            if(nx >= 0 and nx < w and ny >= 0 and ny < h):
                if(graph[ny][nx] == 1 and visited[ny][nx] == 0):
                    visited[ny][nx] = 1
                    bfs(ny, nx)



    count = 0
    for x in range(w):
        for y in range(h):
            if(graph[y][x] == 1 and visited[y][x] == 0):
                visited[y][x] = 1
                bfs(y, x)
                count += 1
    print(count)