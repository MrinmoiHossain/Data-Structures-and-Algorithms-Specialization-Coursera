def get_max_index(values, weights):
    index = 0
    max_ratio = 0.0

    for i in range(len(values)):
        if weights[i] > 0 and values[i] / weights[i] > max_ratio:
            max_ratio = values[i] / weights[i]
            index = i

    return index

def get_optimal_value(capacity, weights, values):
    value = 0.0
    
    for _ in range(len(weights)):
        if capacity == 0:
            return value

        index = get_max_index(values, weights)
        a = min(capacity, weights[index])
        value += (a * values[index]) / weights[index]
        weights[index] -= a
        capacity -= a

    return value


if __name__ == "__main__":
    n, capacity = map(int, input().split())
    values = []
    weights = []
    for _ in range(n):
        a, b = map(int, input().split())
        values.append(a)
        weights.append(b)

    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
