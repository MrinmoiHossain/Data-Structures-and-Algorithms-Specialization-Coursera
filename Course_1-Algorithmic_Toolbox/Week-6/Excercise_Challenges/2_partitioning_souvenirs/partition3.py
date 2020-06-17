import numpy as np

def partition3(A):
    sums = sum(A)
    W = sums // 3

    if W * 3 != sums:
        return 0

    n = len(A)
    dp = np.zeros((n + 1, W + 1))

    for i in range(n + 1):
        for j in range(W + 1):
            if A[i - 1] <= j:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A[i - 1]] + A[i - 1])
            else:
                dp[i][j] = dp[i - 1][j]

    return W == int(dp[n][W])

if __name__ == '__main__':
    n = int(input())
    A = list(map(int, input().split()))
    
    result = partition3(A)
    print(1 if result else 0)

