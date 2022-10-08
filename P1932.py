# n = int(input())
# table = []
# for i in range(n):
#     table.append(list(map(int, input().split())))

# for i in range(1, n):
#     for j in range(i+1):
#         if (j == 0):
#             table[i][j] += table[i-1][0]
#         elif (j == i):
#             table[i][j] += table[i-1][-1]
#         else:
#             table[i][j] += max(table[i-1][j-1], table[i-1][j])

# print(max(table[-1]))

n = int(input())
table = []
for i in range(n):
    table.append(list(map(int, input().split())))

t = []
for i in range(2**(n-1)):
    temp_value = table[0][0]
    temp_idx = 0
    idx = 0
    for value in bin(i)[2:].zfill(n-1):
        temp_idx += int(value)
        temp_value += table[idx+1][temp_idx]
        idx+=1
    t.append(temp_value)

print(max(t))