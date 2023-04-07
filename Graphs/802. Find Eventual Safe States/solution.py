class Solution:
    def dfs(self, node, visited, pathvisited, adj,safenodes):
        visited[node] = 1
        pathvisited[node] = 1
        for i in adj[node]:
            if visited[i] == 0:
                if self.dfs(i,visited,pathvisited, adj,safenodes):
                    return True
            elif pathvisited[i] == 1:
                return True
        pathvisited[node] = 0
        safenodes[node] = 1
        return False
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        V = len(graph)
        visited = [0 for i in range(V)]
        pathvisited = [0 for i in range(V)]
        safenodes = [0 for i in range(V)]
        ls = []
        for i in range(V):
            if not visited[i]:
                self.dfs(i, visited,pathvisited,graph,safenodes)
        for i in range(V):
            if safenodes[i] == 1:
                ls.append(i)
        return ls
