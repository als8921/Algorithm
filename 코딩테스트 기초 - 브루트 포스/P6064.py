n = int(input())
for _ in range(n):
    M, N, x, y = map(int, input().split())
    while(1):
        if(x > M*N):
            print(-1)
            break
        if((x-y) % N == 0):
            print(x)
            break
        x += M