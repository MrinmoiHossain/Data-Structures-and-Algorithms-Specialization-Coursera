def optimal_points(segments):
    last = segments[0][1]
    points = [last]

    for seg in segments:
        if seg[0] <= last:
            continue

        last = seg[1]
        points.append(last)
    
    return points

if __name__ == '__main__':
    n = int(input())
    segments = []
    for _ in range(n):
        a, b = map(int, input().split())
        segments.append([a, b])
    
    segments.sort(key = lambda x : x[1])

    points = optimal_points(segments)
    print(len(points))
    print(*points)
