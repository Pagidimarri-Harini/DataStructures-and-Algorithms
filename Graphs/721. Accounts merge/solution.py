from collections import OrderedDict
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
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        emails = {}
        ds = DisjointSet(len(accounts))
        for i in range(len(accounts)):
            for j in accounts[i][1:]:
                if j not in emails:
                    emails[j] = i
                else:
                    ds.union(i,emails[j])
        mergedacc = [[] for i in range(len(accounts))]
        for i in emails:
            node = emails[i]
            parent = ds.findParent(node)
            mergedacc[parent].append(i)
        ans = [[accounts[i][0]]+sorted(mergedacc[i]) for i in range(len(mergedacc)) if mergedacc[i] != []]
        return ans

