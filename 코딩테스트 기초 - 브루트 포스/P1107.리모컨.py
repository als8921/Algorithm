n = int(input())
m = int(input())

delList = []
if(m > 0):
    delList = list(map(str, input().split()))

result = abs(n-100)
for num in range(1000000):
    check = True
    for i in delList:
        if i in str(num):
            check = False

    if(check):
        count = len(str(num)) + abs(num-n)
        if(count < result):
            result = count
print(result)