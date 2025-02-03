n = int(input())
for _ in range(n):
    cmd = input()
    count = 0
    for i in cmd:
        if i=="(":
            count += 1
        elif i==")":
            count -= 1
        if count < 0:
            break
    if(count==0):
        print("YES")
    else:
        print("NO")