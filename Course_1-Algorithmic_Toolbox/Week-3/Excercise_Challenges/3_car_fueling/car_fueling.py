def compute_min_refills(stops, n, L):
    num_refill = 0
    current_refill = 0

    while current_refill <= n:
        last_refill = current_refill

        while(current_refill <= n and stops[current_refill + 1] - stops[last_refill] <= L):
            current_refill += 1

        if current_refill == last_refill:
            return -1

        if current_refill <= n:
            num_refill += 1

    return num_refill

if __name__ == '__main__':
    d = int(input())
    m = int(input())
    n = int(input())
    stops = list(map(int, input().split()))
    stops = [0] + stops + [d]

    print(compute_min_refills(stops, n, m))
