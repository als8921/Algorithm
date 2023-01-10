# 1 1 1 2 2 3 4 5 7 9 12 12+4 16+5
# p[n] = p[n-1] + p[n-5]
p = [0, 1, 1, 1, 2] + [-1] * 100
print(p)

def dp(n):
    if(p[n] == -1):
        p[n] = dp(n-1) + dp(n-5)
    return p[n]

n = int(input())
for i in range(n):
    print(dp(int(input())))