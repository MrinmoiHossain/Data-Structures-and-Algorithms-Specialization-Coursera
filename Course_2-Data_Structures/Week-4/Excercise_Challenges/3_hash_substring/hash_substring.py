class RabinKarp:
    def __init__(self):
        self.pattern = ''
        self.text = ''
        self.pattern_len = 0
        self.text_len = 0
        self.bound = 0
        self.hash_list = []
        self.find_index = []

    def hash_func(self, s):
        h = 0
        for a in s:
            h += ord(a)

        return h

    def precompute_hashes(self):
        self.hash_list = [self.hash_func(self.text[:self.pattern_len])]
        
        for i in range(1, self.bound):
            old_hash = self.hash_list[i - 1]
            left_hash = ord(self.text[i - 1])
            right_hash = ord(self.text[i + self.pattern_len - 1])

            total_hash = old_hash - left_hash + right_hash
            self.hash_list.append(total_hash)

    def get_occurrences(self):
        pattern_hash = self.hash_func(self.pattern)

        self.precompute_hashes()
        for i in range(self.bound):
            if pattern_hash == self.hash_list[i]:
                if self.pattern == self.text[i : i + self.pattern_len]:
                    self.find_index.append(i)

    def read_input(self):
        self.pattern = input()
        self.text = input()

        self.pattern_len = len(self.pattern)
        self.text_len = len(self.text)
        self.bound = self.text_len - self.pattern_len + 1

    def print_occurrences(self):
        print(" ".join(map(str, self.find_index)))

    def solve(self):
        self.read_input()
        self.get_occurrences()
        self.print_occurrences()


if __name__ == '__main__':
    obj = RabinKarp()
    obj.solve()


