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
        if self.size[p1] < self.size[p2]:
            self.parent[p1] = self.parent[p2]
            self.size[p2] += self.size[p1]
        else:
            self.parent[p2] = self.parent[p1]
            self.size[p2] += self.size[p1]
            
class Solution:
    def spanningTree(self, V, adj):
        obj = DisjointSet(V)
        edges = []
        totwt = 0
        for i in range(V):
            for u,wt in adj[i]:
                edges.append([i,u,wt])
        
        edges.sort(key = lambda x : x[2])
        for i in edges:
            if obj.findParent(i[0]) != obj.findParent(i[1]):
                totwt += i[2]
                obj.union(i[0], i[1])
        return totwt 
