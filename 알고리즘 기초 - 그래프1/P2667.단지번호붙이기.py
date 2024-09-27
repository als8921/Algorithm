count = 0
def solution():
    n = int(input())

    graph = []
    visited = [[0] * n for _ in range(n)]

    for i in range(n):
        graph.append(input())

    dx = (-1, 1, 0, 0)
    dy = (0, 0, -1, 1)

    stack = []
    result = []

    def bfs(x, y):
        count += 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if(nx >= 0 and nx < n and ny >= 0 and ny < n):
                if(graph[ny][nx] == "1" and visited[ny][nx] == 0):
                    visited[ny][nx] = 1
                    bfs(nx, ny)



    for x in range(n):
        for y in range(n):
            if(graph[y][x] == "1"):
               bfs(x, y)
    
    print(count)
    # result.sort()
    # print(len(result))
    # for i in result:
    #     print(i)


solution()