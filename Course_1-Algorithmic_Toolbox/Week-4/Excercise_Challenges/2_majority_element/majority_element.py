def get_majority_element(a, left, right):
    if left == right:
        return -1
    if left + 1 == right:
        return a[left]
    
    mid = (left + right - 1) // 2 + 1
    
    left_element = get_majority_element(a, left, mid)
    right_element = get_majority_element(a, mid, right)

    left_count = 0
    for v in a[left:right]:
        if v == left_element:
            left_count += 1

    if left_count > (right - left) // 2:
        return left_element

    right_count = 0
    for v in a[left:right]:
        if v == right_element:
            right_count += 1

    if right_count > (right - left) // 2:
        return right_element
        
    return -1

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))

    
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)
