import sys
s = list(sys.stdin.readline().rstrip())
s2 = []

for _ in range(int(sys.stdin.readline())):
    cmd = list(sys.stdin.readline().split())
    if(cmd[0] == "P"):
        s.append(cmd[1])
    elif(cmd[0] == "L"):
        if(len(s)>0):
            s2.append(s.pop())
    elif(cmd[0] == "D"):
        if(len(s2)>0):
            s.append(s2.pop())
    elif(cmd[0] == "B"):
        if(len(s)>0):
            s.pop()
s2.reverse()
for i in s:
    print(i, end="")
for i in s2:
    print(i, end="")