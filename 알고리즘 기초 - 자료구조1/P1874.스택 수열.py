n = int(input())
num = list(range(n, 0, -1))
stack = []
result = []
cmd = []
for i in range(n):
    cmd.append(int(input()))
    
for i in cmd:
    if(len(stack)==0):
        stack.append(num.pop())
        result.append("+")

    
    if stack[-1] > i:
        result = ["NO"]
        break
    else:
        while(stack[-1] != i):
            stack.append(num.pop())
            result.append("+")
        if stack[-1] == i:
            stack.pop()
            result.append("-")

for i in result:
    print(i)