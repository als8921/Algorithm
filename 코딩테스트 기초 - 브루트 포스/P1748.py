n = int(input())
m = len(str(n))
result = n * m
for i in range(m-1, 0, -1):
    result -= ((10**(i)-1))
print(result)