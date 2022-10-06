n = int(input())
cmd = []
stack = []
for i in range(n):
    cmd.append(input())
    if(cmd[:4]=="push"):
        print(cmd[:4], cmd[5:])
        stack.append(cmd[5:])