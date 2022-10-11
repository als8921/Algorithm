n, money = map(int, input().split())
m = []
for i in range(n):
    m.append(int(input()))
m.reverse()
result = 0
for i in m:
    result += (money//i)
    money %= i
    if money==0:
        break
print(result)