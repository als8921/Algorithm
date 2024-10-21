n, b = map(int, input().split())

result = ""
while(n > 0):
    temp = n % b
    if(temp >= 10):
        result = chr(temp + 55) + result
    else:
        result = str(temp) + result
    n//=b

print(result)