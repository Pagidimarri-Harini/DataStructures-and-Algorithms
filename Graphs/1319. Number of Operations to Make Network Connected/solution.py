class DisjointSet:
    def __init__(self,n):
        self.parent = [i for i in range(n)]
        self.size = [1]*n
        self.count = 0
    def findParent(self, node):
        if self.parent[node] == node:
            return node
        self.parent[node] = self.findParent(self.parent[node])
        return self.parent[node]
    def union(self, n1, n2):
        p1 = self.findParent(n1)
        p2 = self.findParent(n2)
        if p1 == p2:
            self.count += 1
        elif self.size[p1] < self.size[p2]:
            self.parent[p1] = self.parent[p2]
            self.size[p2] += self.size[p1]
        else:
            self.parent[p2] = self.parent[p1]
            self.size[p2] += self.size[p1]
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        ds = DisjointSet(n)
        for i in connections:
            ds.union(i[0], i[1])
        s = len([i for i in range(n) if i == ds.parent[i]]) -1
        if ds.count >= s:
            return s
        return -1
