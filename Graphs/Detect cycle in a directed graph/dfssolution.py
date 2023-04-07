class Solution:
    def dfs(self, node, visited, pathvisited, adj):
        visited[node] = 1
        pathvisited[node] = 1
        for i in adj[node]:
            if visited[i] == 0:
                if self.dfs(i,visited,pathvisited, adj):
                    return True
            elif pathvisited[i] == 1:
                return True
        pathvisited[node] = 0
        return False
            
        
    
    #Function to detect cycle in a directed graph.
    def isCyclic(self, V, adj):
        visited = [0 for i in range(V)]
        pathvisited = [0 for i in range(V)]
        for i in range(V):
            if visited[i] == 0:
                if self.dfs(i, visited,pathvisited,adj):
                    return True
        return False
