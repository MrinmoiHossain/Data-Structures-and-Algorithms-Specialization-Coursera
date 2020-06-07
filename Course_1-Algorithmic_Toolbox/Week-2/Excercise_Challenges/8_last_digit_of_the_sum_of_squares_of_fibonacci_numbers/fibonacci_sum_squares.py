PISANO = 60

def last_digit_of_fibonacci(n):
    if n < 2:
        return n

    previous = 0
    current  = 1

    for _ in range(2, n + 1):
        temp = (previous + current) % 10
        previous = current
        current = temp

    return current % 10

def fibonacci_sum_squares_fast(n):
    one_side   = last_digit_of_fibonacci(n % PISANO)
    other_side = last_digit_of_fibonacci((n + 1) % PISANO)

    return (one_side * other_side) % 10

def fibonacci_sum_squares_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current * current

    return sum % 10

if __name__ == '__main__':
    n = int(input())
    print(fibonacci_sum_squares_fast(n))
