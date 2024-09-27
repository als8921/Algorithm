def solution():
    V, E = map(int, input().split())
    # N : 정점의 개수, M : 간선의 개수
    graph= [[] for _ in range(V+1)]    # 그래프
    visited = [False] * (V+1)   # 연결되었는지 방문 여부 체크
    depth = [-1] * (V+1)
    
    for i in range(E):
        u, v = map(int, input().split())
        # u, v : 간선의 양 끝점
        graph[u].append(v)
        graph[v].append(u)

    stack = []
    result = True
    for i in range(1, V+1):
        if(not visited[i]): # 방문하지 않은 노드라면 스택에 넣기
            stack.append(i)
            depth[i] = 0

        connected = []
        while(stack):  
            current_node = stack.pop()  # 스택에서 하나씩 빼며 방문처리
            if(not visited[current_node]):
                visited[current_node] = True
                for child_node in graph[current_node]:
                    stack.append(child_node)  # 스택에 자식노드 넣기
                    if(depth[child_node] == -1):
                        depth[child_node] = (depth[current_node] + 1) %2
                    elif(depth[child_node]== depth[current_node]):
                        result = False
                    else:
                        depth[child_node] = depth[current_node] + 1
    
    print("YES" if result else "NO")


n = int(input())
for _ in range(n):
    solution()