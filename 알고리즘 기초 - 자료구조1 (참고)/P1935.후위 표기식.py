n = int(input())
cmd = input()
num = [0] * n
stack = []
for i in range(n):
    num[i] = int(input())

for i in cmd:
    if(ord(i) >= 65 and ord(i) <= 90):
        stack.append(num[ord(i)-65])
    elif(i == '+'):
        n2 = stack.pop()
        n1 = stack.pop()
        stack.append(n1+n2)

    elif(i == '-'):
        n2 = stack.pop()
        n1 = stack.pop()
        stack.append(n1-n2)

    elif(i == '*'):
        n2 = stack.pop()
        n1 = stack.pop()
        stack.append(n1*n2)

    elif(i == '/'):
        n2 = stack.pop()
        n1 = stack.pop()
        stack.append(n1/n2)


print('%.2f' %stack[0])