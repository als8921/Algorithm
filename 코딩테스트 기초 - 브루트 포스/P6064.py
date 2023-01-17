n = int(input())
for _ in range(n):
    M, N, x, y = map(int, input().split())
    X, Y = x, y
    while(True):
        if(X > M*N or Y > M*N):
            print(-1)
            break
        if(X == Y):
            print(X)
            break
        elif(X < Y):
            X += M
        elif(X > Y):
            Y += N