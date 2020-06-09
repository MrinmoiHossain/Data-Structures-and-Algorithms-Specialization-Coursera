def is_greater_or_equal(a, b):
    return int(a+b) >= int(b+a)

def largest_number(a):
    max_number = ''
    while a:
        max_digit = '0'

        for digit in a:
            if is_greater_or_equal(digit, max_digit):
                max_digit = digit
        
        max_number += max_digit
        a.remove(max_digit)

    return max_number

if __name__ == '__main__':
    n = int(input())
    a = list(input().split())
    print(largest_number(a))
    
