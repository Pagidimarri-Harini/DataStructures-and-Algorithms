# Union by size
class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.size = [1] * n

    def find(self, i):
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, i, j):
        i_root = self.find(i)
        j_root = self.find(j)
        if i_root == j_root:
            return
        if self.size[i_root] < self.size[j_root]:
            self.parent[i_root] = j_root
            self.size[j_root] += self.size[i_root]
        else:
            self.parent[j_root] = i_root
            self.size[i_root] += self.size[j_root]
