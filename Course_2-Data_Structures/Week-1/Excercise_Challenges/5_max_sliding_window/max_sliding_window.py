from collections import deque

def max_sliding_window_fast(sequence, w):
    dq = deque()

    for i in range(w):
        while dq and sequence[i] >= sequence[dq[-1]]:
            dq.pop()
        dq.append(i)

    for i in range(w, n):
        print(sequence[dq[0]], end=" ")

        while dq and dq[0] <= i - w:
            dq.popleft()

        while dq and sequence[i] >= sequence[dq[-1]]:
            dq.pop()

        dq.append(i)
    
    print(sequence[dq[0]])

def max_sliding_window_naive(sequence, m):
    maximums = []
    for i in range(len(sequence) - m + 1):
        maximums.append(max(sequence[i:i + m]))

    return maximums

if __name__ == '__main__':
    n = int(input())
    input_sequence = list(map(int, input().split()))
    window_size = int(input())

    max_sliding_window_fast(input_sequence, window_size)

