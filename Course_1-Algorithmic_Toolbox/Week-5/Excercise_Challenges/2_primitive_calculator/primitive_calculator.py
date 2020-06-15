def optimal_sequence_dp(n):
    cal = [0] * (n + 1)

    for i in range(1, n+1):
        cal[i] = cal[i - 1] + 1
        if i % 2 == 0:
            cal[i] = min(cal[i], cal[i // 2] + 1)
        if i % 3 == 0:
            cal[i] = min(cal[i], cal[i // 3] + 1)

    sequence = [n]
    while n != 1:
        if n % 3 == 0 and cal[n] - 1 == cal[n // 3]:
            sequence.append(n // 3)
            n = n//3
        elif n % 2 == 0 and cal[n] - 1 == cal[n // 2]:
            sequence.append(n // 2)
            n = n//2
        else:
            sequence.append(n - 1)
            n -= 1

    return sequence[::-1]

def optimal_sequence(n):
    sequence = []
    while n >= 1:
        sequence.append(n)
        if n % 3 == 0:
            n = n // 3
        elif n % 2 == 0:
            n = n // 2
        else:
            n = n - 1
    return reversed(sequence)

if __name__ == '__main__':
    n = int(input())
    
    sequence = list(optimal_sequence_dp(n))
    print(len(sequence) - 1)
    for x in sequence:
        print(x, end=' ')
