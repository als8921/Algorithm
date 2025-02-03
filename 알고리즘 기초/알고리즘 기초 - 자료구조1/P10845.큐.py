import sys
n = int(sys.stdin.readline())
queue = []
for _ in range(n):
    cmd = list(sys.stdin.readline().split())
    if(cmd[0] == "push"):
        queue.append(int(cmd[1]))
    elif(cmd[0] == "size"):
        print(len(queue))
    elif(cmd[0] == "pop"):
        print(queue.pop(0) if len(queue) > 0 else -1)
    elif(cmd[0] == "back"):
        print(queue[-1] if len(queue) > 0 else -1)
    elif(cmd[0] == "front"):
        print(queue[0] if len(queue) > 0 else -1)
    elif(cmd[0] == "empty"):
        print(0 if len(queue) > 0 else 1)