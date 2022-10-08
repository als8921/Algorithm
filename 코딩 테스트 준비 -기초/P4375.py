while(1):
    try:
        n = int(input())
        a = 1
        i = 1
        while(1):
            if(a%n ==0):
                print(i)
                break
            a+=10**i
            i+=1
    except:
        break