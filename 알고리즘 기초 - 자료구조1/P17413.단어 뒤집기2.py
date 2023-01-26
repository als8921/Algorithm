s =  input()
start = 0
end = -1
i = 0
while(True):
    end = i
    if(s[i] == "<"):
        start = i
        while (s[i] != ">"):
            i+=1
            end = i
        print(s[start:i+1], end="")
        start = i+1

    else:
        if(s[start]==" "):
            print(" ", end = "")
            start += 1
            i+=1
        if(i+1 == len(s)):
            print(s[start:end+1][::-1], end = "")

        elif(s[i+1]==" "):
            print(s[start:end+1][::-1], end = " ")
            start = i+2
        elif(s[i+1]=="<"):
            print(s[start:end+1][::-1], end = "")
            start = i+2

    i+=1
    if(i >= len(s)):
        break