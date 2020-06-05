def fib_naive(n):
    if n <= 1:
        return n
    return fib_naive(n - 1) + fib_naive(n - 2)

def fib_fast(n):
    F = []
    F.append(0)
    F.append(1)

    for i in range(2, n + 1):
        F.append(F[i - 1] + F[i - 2])

    return F[n]

def fib_math(n):
    golden_ration = (1 + 5 ** 0.5) / 2
    return int((golden_ration ** n + 1) / 5 ** 0.5)

if __name__ == '__main__':
    n = int(input())
    print(fib_math(n))
