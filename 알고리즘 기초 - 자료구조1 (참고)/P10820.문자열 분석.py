while True:
    try:
        sentence = input()
        arr = [0, 0, 0, 0]
        for i in sentence:
            if(i == " "):
                arr[3] += 1
            elif(ord(i) >= 97 and ord(i) <= 122):
                arr[0] += 1
            elif(ord(i) >= 65 and ord(i) <= 90):
                arr[1] += 1
            elif(ord(i) >= 48 and ord(i) <= 57):
                arr[2] += 1
            else:
                break

        for i in arr:
            print(i, end = " ")
    except EOFError:
        break