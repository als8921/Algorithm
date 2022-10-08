table = [0] * 1000001

for i in range(1, 1000001):
    for j in range(i, 1000001, i):
        table[j]+=i
    table[i]+=table[i-1]

n = int(input())
for i in range(n):
    print(table[int(input())])