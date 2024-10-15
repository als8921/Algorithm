"""
문제
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

입력
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 답을 출력한다.
"""
def main():
    n = int(input())
    arr = list(map(int, input().split()))
    

    arr_sum = [0] * n
    arr_sum[0] = arr[0]
    for i in range(1, n):
        arr_sum[i] = arr_sum[i-1] + arr[i]
    result = [arr[0]]
    arr_sum_min = 0     # 안 빼도 되는 경우가 0임
    for i in range(1, n):
        arr_sum_min = min(arr_sum_min, arr_sum[i-1])
        result.append(arr_sum[i] - arr_sum_min)

    print(max(result))

main()

"""
10  -4  3   1   5   6   -35 12  21  -1
===
10  6   9   10  15  21  -14 -2  19  18
S0  S1  S2  S3  S4  S5  S6  S7  S8  S9

a4 + a5 + a6 = S6 - S3

Sn - min(S[:n-1])

k = n to 0
Sk - min(S[:k-1])


"""