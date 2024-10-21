n, b = input().split()
result = 0
for idx, i in enumerate(n[::-1]):
    if(ord(i)>= 65):
        result += (ord(i) - 55) * (int(b)**idx)
    else:
        result += int(i)* (int(b)**idx)

print(result)