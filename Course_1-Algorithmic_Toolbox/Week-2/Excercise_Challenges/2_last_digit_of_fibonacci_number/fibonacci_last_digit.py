def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % 10

def get_fibonacci_last_digit_fast(n):
    if n <= 1:
        return n

    prev = 0
    curr = 1

    for _ in range(n - 1):
        prev, curr = curr, (prev + curr) % 10

    return curr % 10

if __name__ == '__main__':
    n = int(input())
    print(get_fibonacci_last_digit_fast(n))
