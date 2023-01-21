n = int(input())
userInfo = []
for i in range(n):
    temp = input().split()
    userInfo.append([int(temp[0]), temp[1]])

userInfo = sorted(userInfo, key = lambda x: x[0])

for age, name in userInfo:
    print(age, name)