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
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ds = DisjointSet(n*n)
        xdir = [-1,0,1,0]
        ydir = [0,1,0,-1]
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    for k in range(4):
                        newx = i + xdir[k]
                        newy = j + ydir[k]
                        if newx >= 0 and newx < n and newy >= 0 and newy < n and grid[newx][newy] == 1:
                            n2 = newx * n + newy
                            n1 = i * n + j
                            ds.union(n1, n2)
        maxarea = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    area = 0
                    x = set()
                    for k in range(4):
                        newx = i + xdir[k]
                        newy = j + ydir[k]
                        if newx >= 0 and newx < n and newy >= 0 and newy < n and grid[newx][newy] == 1:
                            x.add(ds.findParent(newx*n+newy))
                    for k in x:
                        area += ds.size[k]
                    maxarea = max(maxarea, area+1)
        return max(maxarea, ds.size[ds.findParent((n-1)*(n-1))])
                

