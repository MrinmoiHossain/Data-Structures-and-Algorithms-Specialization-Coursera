import numpy as np

def edit_distance(s1, s2):
    n, m = len(s1), len(s2)
    D = np.zeros((n + 1, m + 1))

    for i in range(m + 1):
        D[0][i] = i
    for i in range(n + 1):
        D[i][0] = i

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            match = D[i - 1][j - 1]
            mismatch = D[i - 1][j - 1] + 1
            insertion = D[i][j - 1] + 1
            deletion = D[i - 1][j] + 1

            if s1[i - 1] == s2[j - 1]:
                D[i][j] = min(insertion, deletion, match)
            else:
                D[i][j] = min(insertion, deletion, mismatch)

    return int(D[n][m])

if __name__ == "__main__":
    a = input()
    b = input()
    print(edit_distance(a, b))
