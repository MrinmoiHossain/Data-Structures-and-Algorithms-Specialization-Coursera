import numpy as np

def lcs3(a, b, c):
    n, m, l = len(a), len(b), len(c)
    dp = np.zeros((n + 1, m + 1, l + 1))

    for i in range(n + 1):
        for j in range(m + 1):
            for k in range(l + 1):
                if i == 0 or j == 0 or k == 0:
                    dp[i][j][k] = 0
                elif a[i - 1] == b[j - 1] and a[i - 1] == c[k - 1]:
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1]
                else:
                    dp[i][j][k] = max(dp[i - 1][j][k],
                                      dp[i][j - 1][k],
                                      dp[i][j][k - 1])
    
    return int(dp[n][m][l])

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))

    n = int(input())
    b = list(map(int, input().split()))

    n = int(input())
    c = list(map(int, input().split()))
    print(lcs3(a, b, c))
