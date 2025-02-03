N = int(input())    # 구매해야 하는 카드의 개수
price = [0] + list(map(int, input().split())) 

table = [0] * (N+1)

def dp(n):
    if(table[n] != 0):
        return table[n]
        
    temp = [price[n]]
    for i in range(1, n//2 + 1):
        temp.append(dp(i) + dp(n-i))
    table[n] = max(temp)
    return max(temp)
            

dp(N)
print(table[-1])
