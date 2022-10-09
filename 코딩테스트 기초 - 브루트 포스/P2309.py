heights = []
t = [0] * 100
for i in range(9):
    n = int(input())
    heights.append(n)
    t[n] = 1

result = heights[:]
num = sum(heights) - 100
for i in heights:
    if(num-i != i and t[num-i]==1):
        result.remove(num-i)
        result.remove(i)
        break

result.sort()
for i in result:
    print(i)