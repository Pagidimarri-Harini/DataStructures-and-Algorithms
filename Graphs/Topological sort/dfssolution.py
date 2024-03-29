#topological sort- linear ordering of vertices such that if there is an edge btwn u and v then u appears before v in the ordering
#topological sort is only applicable for directed acyclic graph(DAG)
from queue import LifoQueue
class Solution:
    def dfs(self, node, visited, adj,stack):
        visited[node] = 1
        for i in adj[node]:
            if not visited[i]:
                self.dfs(i,visited,adj,stack)
        stack.put(node)
    def topoSort(self, V, adj):
        visited = [0 for i in range(V)]
        stack = LifoQueue()
        for i in range(V):
            if not visited[i]:
                self.dfs(i, visited,adj,stack)
        ls = []
        while not stack.empty():
            ls.append(stack.get())
        return ls
