# 1번째 방법

# 2번째 방법
f = [0]*100
f[0]=1
f[1]=1

def fib(n):
    global fib_num
    fib_num+=1
    if n<=2:
        return 1
    else:
        return (fib(n-1) + fib(n-2))

fib_num = 0
fib(5)
print(fib_num)

5
4 3
3 2 2 1