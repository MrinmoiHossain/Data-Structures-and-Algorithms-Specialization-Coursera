import numpy as np

def lcs2(a, b):
    n, m = len(a), len(b)
    D = np.zeros((n + 1, m + 1))

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if a[i - 1] == b[j - 1]:
                D[i][j] = 1 + D[i - 1][j - 1]
            else:
                D[i][j] = max(D[i - 1][j], D[i][j - 1])

    return int(D[n][m])

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))

    m = int(input())
    b = list(map(int, input().split()))

    print(lcs2(a, b))
