cnt = 0
def fib(n):
    global cnt
    if n <= 2:
        cnt += 1
        return 1
    else:
        return fib(n-2)+fib(n-1)
f = [0] * 100
f[1] = 1
f[2] = 1
def fibonacci(n):
    global cnt
    if f[n] == 0:
        cnt+=1
        f[n] = fibonacci(n-1) + fibonacci(n-2)
    return f[n]

n = int(input())
fib(n)
print(cnt, end = " ")
cnt = 0
fibonacci(n)
print(cnt)