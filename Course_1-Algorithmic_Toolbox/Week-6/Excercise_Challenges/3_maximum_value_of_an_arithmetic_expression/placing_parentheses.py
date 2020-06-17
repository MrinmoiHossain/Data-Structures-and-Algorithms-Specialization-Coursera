import numpy as np

def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b

def is_operate(a):
    return (a == '+' or a == '-' or a == '*')

def get_maximum_value(dataset):
    operator = []
    nums = []

    for v in dataset:
        if is_operate(v):
            operator.append(v)
        else:
            nums.append(int(v))

    n = len(nums)
    min_dp = np.zeros((n, n))
    max_dp = np.zeros((n, n))

    for i in range(n):
        for j in range(n):
            if i == j:
                min_dp[i][j] = max_dp[i][j] = nums[i]

    for i in range(n - 1):
        for j in range(n - i - 1):
            k = i + j + 1
            min_val = 2**64
            max_val = -2**64

            for l in range(j, k):
                a = evalt(min_dp[j][l], min_dp[l + 1][k], operator[l])
                b = evalt(min_dp[j][l], max_dp[l + 1][k], operator[l])
                c = evalt(max_dp[j][l], min_dp[l + 1][k], operator[l])
                d = evalt(max_dp[j][l], max_dp[l + 1][k], operator[l])

                min_val = min(min_val, a, b, c, d)
                max_val = max(max_val, a, b, c, d)
            
            min_dp[j][k] = min_val
            max_dp[j][k] = max_val

    return int(max_dp[0][n - 1])
    
if __name__ == "__main__":
    s = input()
    print(get_maximum_value(s))
