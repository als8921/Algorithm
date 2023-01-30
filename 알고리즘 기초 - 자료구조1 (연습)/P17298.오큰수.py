import sys
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
stack = []
result = [-1] * len(arr)
for i in range(len(arr)):
    num = arr[i]
    while(stack):
        if(num > arr[stack[-1]]):
            result[stack[-1]] = num
            stack.pop()
        else:
            break
    stack.append(i)
for i in result:
    print(i, end=" ")