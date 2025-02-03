import sys
table = [False, False] + [True]*(1000000)
idx = 2
while(idx < 1000):
    if(table[idx]):
        for i in range(2 * idx, 1000001, idx):
            table[i] = False
    idx+=1

while(1):
    num = int(sys.stdin.readline())

    if(num == 0):
        break
    isTrue = False
    for i in range(3, num):
        if(table[i] and table[num-i]):
            print(f"{num} = {i} + {num-i}")
            isTrue = True
            break
    if(not isTrue):
        print("Goldbach's conjecture is wrong.")