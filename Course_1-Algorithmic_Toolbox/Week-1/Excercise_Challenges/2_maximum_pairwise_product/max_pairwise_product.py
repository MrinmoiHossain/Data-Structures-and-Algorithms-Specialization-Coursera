def max_pairwise_product(numbers):
    max1 = -999
    max2 = -9999
    for value in numbers:
        if value > max1:
            max2 = max1
            max1 = value
        elif value > max2:
            max2 = value

    return max1 * max2


if __name__ == '__main__':
    input_n = int(input())
    input_numbers = [int(x) for x in input().split()]
    print(max_pairwise_product(input_numbers))
