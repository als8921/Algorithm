n = int(input())
table = []
for i in range(n):
    table.append(list(map(int, input().split())))

for i in range(1, n):
    for j in range(i+1):
        if (j == 0):
            table[i][j] += table[i-1][0]
        elif (j == i):
            table[i][j] += table[i-1][-1]
        else:
            table[i][j] += max(table[i-1][j-1], table[i-1][j])

print(max(table[-1]))
