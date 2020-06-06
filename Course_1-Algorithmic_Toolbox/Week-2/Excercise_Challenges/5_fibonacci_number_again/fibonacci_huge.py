def pisano_period(m):
    prev = 0
    curr = 1

    for i in range(m * m):
        temp = (prev + curr) % m
        prev = curr
        curr = temp

        if prev == 0 and curr == 1:
            return i + 1

def get_fibonacci_huge_fast(n, m):
    n %= pisano_period(m)

    prev = 0
    curr = 1

    if n == 0:
        return 0
    elif n == 1:
        return 1

    for _ in range(n - 1):
        temp = (prev + curr) % m
        prev = curr
        curr = temp

    return curr % m

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m

if __name__ == '__main__':
    n, m = map(int, input().split())
    print(get_fibonacci_huge_fast(n, m))
