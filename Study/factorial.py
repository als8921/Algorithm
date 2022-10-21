def fac(n):
    result = 1
    for i in range(1, n+1):
        result *= i
    return result


def factorial(n):
    if(n==1):
        return 1
    return n * factorial(n-1)

table = [0] * 20
table[1] = 1
result = 100
def factorial_dp(n):
    if(table[n]==0):
        table[n] = n * factorial_dp(n-1)
    return table[n]

factorial_dp(3)