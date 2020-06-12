from itertools import chain

def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)

    start_points = zip(starts, ['l'] * len(starts), range(len(starts)))
    end_points = zip(ends, ['r'] * len(ends), range(len(ends)))
    point_points = zip(points, ['p'] * len(points), range(len(points)))

    total_list = chain(start_points, end_points, point_points)
    total_list = sorted(total_list, key=lambda a: (a[0], a[1]))
    cont = 0

    for value, letter, index in total_list:
        if letter == 'l':
            cont += 1
        elif letter == 'r':
            cont -= 1
        else:
            cnt[index] = cont

    return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    n, m = map(int, input().split())
    starts = []
    ends = []
    for _ in range(n):
        a, b = map(int, input().split())
        starts.append(a)
        ends.append(b)

    points = list(map(int, input().split()))
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
