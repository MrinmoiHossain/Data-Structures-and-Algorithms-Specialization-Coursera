def fibonacci_partial_sum_fast(start, finish):
    F = [0, 1]
    PISANO = 60
    for _ in range(PISANO - 2):
        F.append((F[-1] + F[-2]) % 10)
    
    start %= PISANO
    finish %= PISANO
    if finish < start:
        finish += PISANO

    sm = 0
    for i in range(start, finish + 1):
        sm = (sm + F[i % PISANO]) % 10

    return sm % 10

def fibonacci_partial_sum_naive(from_, to):
    sum = 0

    current = 0
    next  = 1

    for i in range(to + 1):
        if i >= from_:
            sum += current

        current, next = next, current + next

    return sum % 10


if __name__ == '__main__':
    start, finish = map(int, input().split())
    print(fibonacci_partial_sum_fast(start, finish))