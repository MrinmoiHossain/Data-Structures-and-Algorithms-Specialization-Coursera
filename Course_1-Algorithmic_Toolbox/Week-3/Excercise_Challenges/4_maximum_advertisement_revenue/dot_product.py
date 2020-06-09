def max_dot_product(a, b):
    a.sort()
    b.sort()
    result = 0

    for i in range(len(a)):
        result += a[i] * b[i]

    return result

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(max_dot_product(a, b))
    
