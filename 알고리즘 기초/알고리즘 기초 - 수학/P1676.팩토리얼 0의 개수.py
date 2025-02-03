n = int(input())

answer = 0
for i in range(5, n+1, 5):
    temp = i
    while(temp%5 == 0):
        answer += 1
        temp //= 5

print(answer)