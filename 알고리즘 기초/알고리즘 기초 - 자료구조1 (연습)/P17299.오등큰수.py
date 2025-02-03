import sys
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
count = dict()
for i in arr:
    if i in count:
        count[i] += 1
    else:
        count[i] = 1

stack = []
result = [-1] * len(arr)
for i in range(len(arr)):
    num = count[arr[i]]
    while(stack):
        if(num > count[arr[stack[-1]]]):
            result[stack[-1]] = arr[i]
            stack.pop()
        else:
            break
    stack.append(i)
for i in result:
    print(i, end=" ")