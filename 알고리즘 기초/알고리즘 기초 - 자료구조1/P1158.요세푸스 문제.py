n, k = map(int, input().split())
numList = list(range(1, n+1))
result = []
i = 0
while(len(numList)!=0):
    i += k-1
    while(i >= len(numList)): i -= len(numList)
    result.append(str(numList.pop(i)))

print("<", (", ".join(result)), ">", sep="")