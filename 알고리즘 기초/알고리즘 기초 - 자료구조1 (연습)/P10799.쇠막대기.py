s = list(input().split("()"))
result = 0
currentNum = 0
for i in s:
    if(i==""):
        result += currentNum
    else:
        temp = 0
        for j in i:
            if(j=="("):
                currentNum += 1
            elif(j==")"):
                temp += 1
        result += currentNum
        currentNum -= temp
        temp = 0

print(result)