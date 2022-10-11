e, s, m = map(int, input().split())

y = 1
while(1):
    if(y%15 == e%15 and y%28 == s%28 and y%19 == m%19):
        print(y)
        break
    y+=1