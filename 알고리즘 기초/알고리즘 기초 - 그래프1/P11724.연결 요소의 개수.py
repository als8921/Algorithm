def solution():
    N, M = map(int, input().split())
    # N : 정점의 개수, M : 간선의 개수
    graph= [[] for _ in range(N+1)]    # 그래프
    visited = [False] * (N+1)   # 연결되었는지 방문 여부 체크
    
    for i in range(M):
        u, v = map(int, input().split())
        # u, v : 간선의 양 끝점
        graph[u].append(v)
        graph[v].append(u)

    connected_count = 0 # 연결요소 카운트
    stack = []
    
    for i in range(1, N+1):
        if(not visited[i]): # 방문하지 않은 노드라면 스택에 넣기
            stack.append(i)
            connected_count += 1

        while(stack):  
            current_node = stack.pop()  # 스택에서 하나씩 빼며 방문처리
            if(not visited[current_node]):
                visited[current_node] = True
                for child_node in graph[current_node]:
                    stack.append(child_node)  # 스택에 자식노드 넣기
        
    print(connected_count)

solution()