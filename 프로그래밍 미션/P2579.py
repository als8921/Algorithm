#   5                   n
#   4 , 1 (2, 2, 1)     n-3 , 2 , 1
#   3 , 2               n-2 , 2
#   아이디어 : 어떤 계단에 도착할 때 2칸으로 도착할 경우, 1칸으로 도착할 경우로 나눈다.
#       2칸으로 도착할 경우 그 전에 어떻게 오던 상관없음
#       1칸으로 도착할 경우 그 전은 무조건 2칸임

n = int(input())
scores = [0] * 300
for i in range(n):
    scores[i] = int(input())

dp = [0] * 300
dp[0] = scores[0]
dp[1] = scores[0] + scores[1]
dp[2] = max(scores[0] + scores[2], scores[1] + scores[2])

for i in range(3, n):
    dp[i] = max(dp[i-3] + scores[i] + scores[i-1], dp[i-2] + scores[i])

print(dp[n-1])