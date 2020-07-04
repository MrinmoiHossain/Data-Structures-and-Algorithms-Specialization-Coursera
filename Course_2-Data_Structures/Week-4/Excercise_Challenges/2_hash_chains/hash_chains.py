class HashChain:
    def __init__(self):
        self.m = 0
        self.multiplier = 263
        self.mod = 1000000007
        self.data = {}

        
    def hash_func(self, s):
        v = 0
        for i in range(len(s)):
            v += (ord(s[i]) * (self.multiplier ** i))
            v %= self.mod
        
        return v % self.m


    def process_query(self, s):
        if s[0] == 'add':
            temp = self.hash_func(s[1])
            
            if temp not in self.data:
                self.data[temp] = [s[1]]
            elif temp in self.data and s[1] not in self.data[temp]:
                self.data[temp].append(s[1])
        
        elif s[0] == 'check':
            temp = int(s[1])

            if temp in self.data:
                for v in self.data[temp][::-1]:
                    print(v, end=" ")
                print()
            else:
                print()
            
        elif s[0] == 'find':
            temp = self.hash_func(s[1])

            if temp not in self.data: 
                print("no")
            else:
                if s[1] not in self.data[temp]:
                    print("no")
                else:
                    print("yes")
                
        elif s[0] == 'del':
            temp = self.hash_func(s[1])

            if temp in self.data and s[1] in self.data[temp]:
                self.data[temp].remove(s[1])

    def read_query(self):
        self.m = int(input())
        q = int(input())

        for _ in range(q):
            s = input().split()
            self.process_query(s)

    def solve(self):
        self.read_query()

if __name__ == '__main__':
    obj = HashChain()
    obj.solve()
