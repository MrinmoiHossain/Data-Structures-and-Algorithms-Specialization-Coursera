PISANO = 60

def fibonacci_sum_fast(n):
    if n < 2:
        return n

    n %= PISANO

    F = [1, 1]
    for _ in range(n):
        F.append((F[-1] + F[-2]) % 10)

    return (F[-1] - 1) % 10

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current

    return sum % 10

if __name__ == '__main__':
    n = int(input())
    print(fibonacci_sum_fast(n))
