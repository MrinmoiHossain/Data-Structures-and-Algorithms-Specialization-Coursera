def lcm_naive(a, b):
    for l in range(1, a*b + 1):
        if l % a == 0 and l % b == 0:
            return l

    return a*b

def gcd_euclid(a, b):
    if b == 0:
        return a
    else:
        return gcd_euclid(b, a % b)

def lcm_fast(a, b):
    return int((a * b) / gcd_euclid(a, b))

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(lcm_fast(a, b))