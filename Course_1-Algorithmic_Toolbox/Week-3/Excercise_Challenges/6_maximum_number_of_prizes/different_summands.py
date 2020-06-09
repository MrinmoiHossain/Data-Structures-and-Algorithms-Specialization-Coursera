def optimal_summands(n):
    summands = []
    for i in range(1, n+1):
        n -= i
        if n == 0 or n <= i:
            summands.append(n + i)
            break
        else:
            summands.append(i)

    return summands

if __name__ == '__main__':
    n = int(input())
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')
