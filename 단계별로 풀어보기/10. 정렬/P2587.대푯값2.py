num = []
for i in range(5):
    num.append(int(input()))

num.sort()
print(int(sum(num)/len(num)))
print(num[2])