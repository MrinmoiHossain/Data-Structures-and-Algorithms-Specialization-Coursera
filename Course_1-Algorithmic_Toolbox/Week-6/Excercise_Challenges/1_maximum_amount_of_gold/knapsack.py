import numpy as np

def optimal_weight(W, w):
    n = len(w)
    dp = np.zeros((n + 1, W + 1))

    for i in range(1, n + 1):
        for j in range(1, W + 1):
            if w[i - 1] <= j:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + w[i - 1])
            else:
                dp[i][j] = dp[i - 1][j]

    return int(dp[n][W])

if __name__ == '__main__':
    W, n = map(int, input().split())
    w = list(map(int, input().split()))
    print(optimal_weight(W, w))
