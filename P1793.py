from math import comb


while (True):
    try:
        n = int(input())
        result = 0
        for i in range(0, n//2 + 1):
            x = n - i*2
            result += comb(i+x, x)*(2**i)
    except:
        break

    print(result)


# t = [0] * 250
# t[1] = 1
# t[2] = 3


# def table(n):
#     global t
#     if (t[n] != 0):
#         return t[n]
#     t[n] = table(n-1) + 2*table(n-2)
#     return t[n]


# result = 0
# while (True):
#     n = int(input())
#     if (n == 0):
#         break
#     result = table(n)
#     print(result)

# print(t)
