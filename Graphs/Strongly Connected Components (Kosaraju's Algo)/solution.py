class Solution:
    def dfs(self, node, stack, visited, adj):
        visited[node] = 1
        for i in adj[node]:
            if visited[i] == 0:
                self.dfs(i, stack, visited, adj)
        stack.append(node)
    def revdfs(self, node, visited, adj):
        visited[node] = 1
        for i in adj[node]:
            if visited[i] == 0:
                self.revdfs(i, visited, adj)
    def kosaraju(self, V, adj):
        visited = [0] * V
        stack = []
        for i in range(V):
            if visited[i] == 0:
                self.dfs(i,stack,visited, adj)
                
        stack= stack[::-1]
        revadj = [[] for i in range(V)]
        for i in range(V):
            for j in adj[i]:
                revadj[j].append(i)
        visited = [0] * V
        count = 0 
        for i in stack:
            if visited[i] == 0:
                self.revdfs(i, visited, revadj)
                count += 1
        return count
            
