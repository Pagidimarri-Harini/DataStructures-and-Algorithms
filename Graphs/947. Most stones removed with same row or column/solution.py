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
            self.size[p1] += self.size[p2]
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        ds = DisjointSet(len(stones))
        x = {}
        y = {}
        for i in range(len(stones)):
            if stones[i][0] in x:
                ds.union(i, x[stones[i][0]])
            if stones[i][1] in y:
                ds.union(i, y[stones[i][1]])
            x[stones[i][0]] = i
            y[stones[i][1]] = i
        numofcomponents = len([i for i in range(len(stones)) if i == ds.parent[i]])
        return len(stones) - numofcomponents
        
