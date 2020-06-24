import sys, threading

# In Python, the default limit on recursion depth is rather low,
# so raise it here for this problem. Note that to take advantage
# of bigger stack, we have to launch the computation in a new thread.
sys.setrecursionlimit(10**7) # max depth of recursion
threading.stack_size(2**27)  # new thread will get stack of such size

class TreeHeight:
    def __init__(self):
        self.n = 0
        self.parent = []
        self.child = []

    def read(self):
        self.n = int(input())
        self.parent = list(map(int, input().split()))
        self.child = [0] * self.n

    def compute_depth(self, node_id):
        parent = self.parent[node_id]
        if parent == -1:
            return 1

        if self.child[node_id]:
            return self.child[node_id]

        self.child[node_id] = 1 + self.compute_depth(self.parent[node_id])
        return self.child[node_id]


    def compute_height(self):
        return max([self.compute_depth(i) for i in range(self.n)])

def main():
  tree = TreeHeight()
  tree.read()
  print(tree.compute_height())

threading.Thread(target=main).start()
