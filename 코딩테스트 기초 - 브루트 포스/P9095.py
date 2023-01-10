n = int(input())
table = [0] * 11
table[0] = 1
table[1] = 2
table[2] = 4

def dp(n):
    if(table[n] == 0):
        table[n] = dp(n-1) + dp(n-2) + dp(n-3)
    return table[n]

for _ in range(n):
    num = int(input())
    print(dp(num-1))