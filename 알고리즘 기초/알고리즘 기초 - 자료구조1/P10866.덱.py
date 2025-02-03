import sys
n = int(sys.stdin.readline())
dec = []
for _ in range(n):
    cmd = list(sys.stdin.readline().split())
    if(cmd[0] == "push_front"):
        dec.insert(0, int(cmd[1]))
    elif(cmd[0] == "push_back"):
        dec.append(int(cmd[1]))
    elif(cmd[0] == "pop_front"):
        print(dec.pop(0) if len(dec) > 0 else -1)
    elif(cmd[0] == "pop_back"):
        print(dec.pop() if len(dec) > 0 else -1)
    elif(cmd[0] == "size"):
        print(len(dec))
    elif(cmd[0] == "empty"):
        print(0 if len(dec) > 0 else 1)
    elif(cmd[0] == "front"):
        print(dec[0] if len(dec) > 0 else -1)
    elif(cmd[0] == "back"):
        print(dec[-1] if len(dec) > 0 else -1)