n = int(input())
num = list(map(int, input().split()))
numSet = sorted(list(set(num)))
numDict = {}
for idx, i in enumerate(numSet):
    numDict[i] = idx
for i in num:
    print(numDict[i], end = " ") 