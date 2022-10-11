t = [0] * 1001
t[1] = 1
t[2] = 3

def table(n):
    global t
    if (t[n] != 0):
        return t[n]
    t[n] = table(n-1) + 2*table(n-2)
    return t[n]

table(999)
result = 0
n = int(input())
result = table(n)
print(result%10007)