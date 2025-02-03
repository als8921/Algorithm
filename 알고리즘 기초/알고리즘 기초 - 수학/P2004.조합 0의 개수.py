n, m = map(int, input().split())
def divCount(n, k):
    temp = 0
    while(n != 0):
        n //= k
        temp += n
    return temp

print(min(divCount(n, 2) - divCount(n-m, 2) - divCount(m, 2), divCount(n, 5) - divCount(n-m, 5) - divCount(m, 5)))