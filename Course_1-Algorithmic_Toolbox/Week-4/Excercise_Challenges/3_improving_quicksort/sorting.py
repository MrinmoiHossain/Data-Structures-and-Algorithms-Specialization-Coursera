import random

def partition3(a, l, r):
    pivot = a[l]
    mid = l

    while mid <= r:
        if a[mid] < pivot:
            a[mid], a[l] = a[l], a[mid]
            mid += 1
            l += 1
        elif a[mid] == pivot:
            mid += 1
        else:
            a[mid], a[r] = a[r], a[mid]
            r -= 1
    
    i, j = l, r
    return i, j

def partition2(a, l, r):
    x = a[l]
    j = l
    for i in range(l + 1, r + 1):
        if a[i] <= x:
            j += 1
            a[i], a[j] = a[j], a[i]
    a[l], a[j] = a[j], a[l]
    return j


def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]

    i, j = partition3(a, l, r)
    randomized_quick_sort(a, l, i - 1)
    randomized_quick_sort(a, j + 1, r)


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))

    randomized_quick_sort(a, 0, n - 1)
    for x in a:
        print(x, end=' ')
