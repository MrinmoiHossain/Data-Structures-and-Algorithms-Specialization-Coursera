def binary_search(a, x):
    left, right = 0, len(a) - 1
    while left <= right:
        mid = int(left + (right - left) / 2)

        if a[mid] == x:
            return mid
        elif a[mid] > x:
            right = mid - 1
        else:
            left = mid + 1

    return -1

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':
    temp = list(map(int, input().split()))
    n = temp[0]
    data = temp[1:]

    temp = list(map(int, input().split()))
    m = temp[0]
    s_data = temp[1:]
    for x in s_data:
        print(binary_search(data, x), end = ' ')
