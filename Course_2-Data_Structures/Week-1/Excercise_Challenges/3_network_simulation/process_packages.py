size = 0
q = []

def process(v):
    while len(q) > 0 and q[0] <= v[0]:
        q.pop(0)

    if len(q) < size:
        if len(q) == 0:
            q.append(v[0] + v[1])
            return v[0]
        else:
            st = max(v[0], q[-1])
            q.append(st + v[1])
            return st
    else:
        return -1

def request_process(A):
    response = []
    for v in A:
        response.append(process(v))

    return response

if __name__ == "__main__":
    size, n = map(int, input().split())

    A = []
    for _ in range(n):
        s, p = map(int, input().split())
        A.append([s, p])

    response_list = request_process(A)

    for response in response_list:
        print(response)
