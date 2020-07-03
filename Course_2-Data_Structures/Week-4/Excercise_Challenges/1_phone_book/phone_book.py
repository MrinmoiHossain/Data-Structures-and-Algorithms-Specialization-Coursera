# python3

class PhoneBook:
    def __init__(self):
        self.n = 0
        self.phone_list = {}

    def read_queries(self):
        self.n = int(input())

        for _ in range(self.n):
            data = input().split()

            if data[0] == 'add':
                self.phone_list[data[1]] = data[2]
            elif data[0] == 'find':
                if data[1] in self.phone_list:
                    print(self.phone_list[data[1]])
                else:
                    print('not found')
            elif data[0] == 'del':
                if data[1] in self.phone_list:
                    self.phone_list.pop(data[1])
        
    def solve(self):
        self.read_queries()
    
if __name__ == '__main__':
    obj = PhoneBook()
    obj.solve()

