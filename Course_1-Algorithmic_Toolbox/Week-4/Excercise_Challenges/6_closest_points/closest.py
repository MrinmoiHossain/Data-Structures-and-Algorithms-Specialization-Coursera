import math

def dist(a, b):
    return math.sqrt((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2)

def naive_minimum_distance(a):
    min_value = float('inf')
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            temp = dist(a[i], a[j])
            if temp < min_value:
                min_value = temp

    return min_value

def stripClosest(strip, d):
    if len(strip) == 0:
        return d

    strip.sort(key = lambda x: x[1])

    for i in range(len(strip)):
        j = i + 1
        while j < len(strip) and (strip[j][1] - strip[i][1]) < d:
            d = min(d, dist(strip[i], strip[j]))
            j += 1

    return d

def closestUtil(a):
    n = len(a)
    if n <= 3:
        return naive_minimum_distance(a)

    mid = n // 2
    midPoint = a[mid]

    dl = closestUtil(a[:mid])
    dr = closestUtil(a[mid:])

    d = min(dl, dr)

    strip = []
    for i in range(n):
        if abs(a[i][0] - midPoint[0]) < d:
            strip.append(a[i])

    return min(d, stripClosest(strip, d))

def fast_minimum_distance(a):
    a.sort(key = lambda x: x[0])

    return closestUtil(a)

if __name__ == '__main__':
    n = int(input())
    l = []

    for _ in range(n):
        x, y = map(int, input().split())
        l.append([x, y])
    
    print("{0:.9f}".format(fast_minimum_distance(l)))
