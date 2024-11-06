"""
문제
수열 A가 주어졌을 때, 그 수열의 증가하는 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가하는 부분 수열은 {1, 2, 50, 60} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가하는 부분 수열의 합을 출력한다.
"""
n = int(input())

arr = [0] + list(map(int, input().split()))
dp = [0] * (n+1)

dp[0] = arr[0]
for i in range(1, n+1):
    maxindex = 0
    for j in range(i):
        if(dp[j] > dp[maxindex] and arr[j] < arr[i]):
            maxindex = j
    if(arr[i] > arr[maxindex]):
        dp[i] = arr[i] + dp[maxindex]
print(max(dp))
"""
1   100 2   50  60  3   5   6   7   8
113 112 112 110 60  23  26  21  15  8



100 1   101
    102 101

"""