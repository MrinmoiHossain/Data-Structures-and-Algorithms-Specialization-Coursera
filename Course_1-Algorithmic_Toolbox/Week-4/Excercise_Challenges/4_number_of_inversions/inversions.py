def get_number_of_inversions(a, b, left, mid, right):
    inv = 0
    i, j, k = left, mid, left

    while i <= mid - 1 and j <= right:
        if a[i] <= a[j]:
            b[k] = a[i]
            i += 1
        else:
            b[k] = a[j]
            inv += mid - i
            j += 1
        k += 1

    while i <= mid - 1:
        b[k] = a[i]
        k += 1
        i += 1

    while j <= right:
        b[k] = a[j]
        k += 1
        j += 1

    for l in range(left, right + 1):
        a[l] = b[l]

    return inv
    

def merge_sort(a, b, left, right):
    inv_count = 0
    if left >= right:
        return inv_count
    
    mid = left + (right - left) // 2

    inv_count += merge_sort(a, b, left, mid)
    inv_count += merge_sort(a, b, mid + 1, right)
    inv_count += get_number_of_inversions(a, b, left, mid + 1, right)

    return inv_count

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    b = n * [0]
    
    print(merge_sort(a, b, 0, len(a) - 1))
