import sys
n = int(sys.stdin.readline())
stack = []
for i in range(n):
    cmd = list(sys.stdin.readline().split())
    if(cmd[0]=="push"):
        stack.append(int(cmd[1]))
    if(cmd[0]=="pop"):
        if(len(stack)>0):
            print(stack.pop())
        else:
            print(-1)
    if(cmd[0]=="size"):
        print(len(stack))
    if(cmd[0]=="empty"):
        if(len(stack)>0):
            print(0)
        else:
            print(1)
    if(cmd[0]=="top"):
        if(len(stack)>0):
            print(stack[-1])
        else:
            print(-1)