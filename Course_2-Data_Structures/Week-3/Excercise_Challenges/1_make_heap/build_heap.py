class BuildHeap:
    def __init__(self):
        self.n = 0
        self.data = []
        self.pair = []

    def read_data(self):
        self.n = int(input())
        self.data = list(map(int, input().split()))

    def left_child(self, index):
        return 2 * index + 1

    def right_child(self, index):
        return 2 * index + 2

    def shift_down(self, index):
        min_index = index

        left = self.left_child(index)
        if left < self.n and self.data[left] < self.data[min_index]:
            min_index = left

        right = self.right_child(index)
        if right < self.n and self.data[right] < self.data[min_index]:
            min_index = right
        
        if index != min_index:
            self.pair.append([index, min_index])
            self.data[index], self.data[min_index] = self.data[min_index], self.data[index]
            self.shift_down(min_index)

    def generate_swap(self):
        for i in range(self.n//2, -1, -1):
            self.shift_down(i)

    def write_pair(self):
        print(len(self.pair))
        for v in self.pair:
            print(v[0], v[1])


if __name__ == "__main__":
    obj = BuildHeap()
    obj.read_data()
    obj.generate_swap()
    obj.write_pair()

