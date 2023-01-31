sentence = input()

for i in sentence:
    if(ord(i) >= 97 and ord(i) <= 122):
        temp = ord(i) + 13
        if temp > 122:
            temp -= 26
        print(chr(temp), end="")
    elif(ord(i) >= 65 and ord(i) <= 90):
        temp = ord(i) + 13
        if temp > 90:
            temp -= 26
        print(chr(temp), end="")
    else:
        print(i, end="")
