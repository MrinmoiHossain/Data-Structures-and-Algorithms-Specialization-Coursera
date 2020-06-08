def get_change(m):
    coin = [1, 5, 10]
    con = 0

    for c in coin[::-1]:
        while c <= m:
            con += 1
            m -= c

    return con


if __name__ == '__main__':
    m = int(input())
    print(get_change(m))
