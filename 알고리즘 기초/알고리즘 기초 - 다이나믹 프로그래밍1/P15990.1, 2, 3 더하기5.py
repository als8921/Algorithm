table = [[0] * 3 for _ in range(100001)]
table[1] = [1, 0, 0]
table[2] = [0, 1, 0]
table[3] = [1, 1, 1]
table[4] = [2, 0, 1]

for n in range(5, 100001):
    table[n][0] = (table[n-1][1] + table[n-1][2]) % 1000000009
    table[n][1] = (table[n-2][0] + table[n-2][2]) % 1000000009
    table[n][2] = (table[n-3][0] + table[n-3][1]) % 1000000009

for _ in range(int(input())):
    N = int(input())
    print(sum(table[N])% 1000000009)

"""
2       table[2] = [0, 1, 0]
===
2

3       table[3] = [1, 1, 1]
===
1 + 2   
2 + 1   
3       

4       table[4] = [2, 0, 1]
===
1 + 3
1 + 2 + 1
3 + 1

5
=== 
1 + dp(4)       table[4][1] + table[4][2]       0 제외  table[n-1][0]
2 + dp(3)       table[3][0] + table[3][2]       1 제외  table[n-2][1]
3 + dp(2)       table[2][0] + table[2][1]       2 제외  table[n-3][2]
"""