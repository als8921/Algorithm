from collections import deque

n, m, v = map(int, input().split())
graph = [[] for i in range(n+1)]
visitedDFS = [0] * (n+1)
visitedBFS = [0] * (n+1)

for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, n+1):
    graph[i].sort()


def dfs(node):
    visitedDFS[node] = 1
    print(node, end = " ")
    for i in graph[node]:
        if(visitedDFS[i] == 0):
            dfs(i)


def bfs(node):
    que = deque()
    que.append(node)
    visitedBFS[v] = 1
    print(node, end = " ")
    while(que):
        for i in graph[que.popleft()]:
            if(visitedBFS[i] == 0):
                visitedBFS[i] = 1
                print(i, end = " ")
                que.append(i)
                


dfs(v)
print()
bfs(v)