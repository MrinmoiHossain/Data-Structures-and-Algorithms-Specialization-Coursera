class DisjointSets:
    def __init__(self):
        self.n = 0
        self.m = 0
        self.data = []
        self.parent = []
        self.rank = []
        self.max_size = 0

    def get_parent(self, table):
        update_parent = []

        root = table
        while root != self.parent[root]:
            update_parent.append(self.parent[root])
            root = self.parent[root]

        for i in update_parent:
            self.parent[i] = root

        return root


    def merge(self, dst, src):
        src_parent = self.get_parent(src)
        dst_parent = self.get_parent(dst)

        if src_parent == dst_parent:
            return

        if self.rank[src_parent] >= self.rank[dst_parent]:
            self.parent[src_parent] = dst_parent
        else:
            self.parent[dst_parent] = src_parent
            if self.rank[src_parent] == self.rank[dst_parent]:
                self.rank[src_parent] += 1

        self.data[dst_parent] += self.data[src_parent]
        self.data[src_parent] = 0

        self.max_size = max(self.max_size, self.data[dst_parent])

    def write_data(self):
        print(self.max_size)

    def read_data(self):
        self.n, self.m = map(int, input().split())
        self.data = list(map(int, input().split()))

        self.parent = [i for i in range(self.n)]
        self.rank = [0] * self.n
        self.max_size = max(self.data)

        for _ in range(self.m):
            destination, source = map(int, input().split())

            self.merge(destination - 1, source - 1)
            self.write_data()


if __name__ == "__main__":
    obj = DisjointSets()
    obj.read_data()
