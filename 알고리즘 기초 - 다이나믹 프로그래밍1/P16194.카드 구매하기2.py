N = int(input())    # 구매해야 하는 카드의 개수
price = [0] + list(map(int, input().split())) 

table = [0] * (N+1)

def dp(n):
    if(table[n]!= 0):
        return table[n]

    temp = [price[n]]
    for i in range(1, n//2 + 1):
        temp.append(dp(i) + dp(n-i))
    table[n] = min(temp)
    return table[n]

dp(N)
print(table[-1])

"""
4
5 2 8 10

4개 카드 구매
1개 : 1         :   
2개 : 2, 1+1    :   
3개 : 3, 2+1    :   
4개 : 4, 2+2    :   

n개 : n, 1+(n-1), 2+(n-2) ... (n//2) + (n - n//2)

"""