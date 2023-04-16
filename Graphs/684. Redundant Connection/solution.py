class DisjointSet:
    def __init__(self,n):
        self.parent = [i for i in range(n)]
        self.size = [1]*n
    def findParent(self, node):
        if self.parent[node] == node:
            return node
        self.parent[node] = self.findParent(self.parent[node])
        return self.parent[node]
    def union(self, n1, n2):
        p1 = self.findParent(n1)
        p2 = self.findParent(n2)
        if p1 == p2:
            return
        elif self.size[p1] < self.size[p2]:
            self.parent[p1] = self.parent[p2]
            self.size[p2] += self.size[p1]
        else:
            self.parent[p2] = self.parent[p1]
            self.size[p2] += self.size[p1]
class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        ds = DisjointSet(len(edges))
        for i in edges:
            if ds.findParent(i[0]-1) == ds.findParent(i[1]-1):
                return [i[0], i[1]]
            else:
                ds.union(i[0]-1, i[1]-1)

