#a graph having even length cycle is bipartite graph 
# no two adjacent nodes must have same color-- if two adjacent nodes have same color then it is not bipartite
class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        color = [1 for i in range(len(graph))]
        paint = 0
        def dfs(graph, start,color,c):
            color[start] = c
            for i in graph[start]:
                if color[i] == 1:
                    if not dfs(graph, i, color, ~c):
                        return False
                elif color[i] == c:
                    return False
            return True
        for i in range(len(graph)):
            if color[i] == 1:
                if not dfs(graph, i, color, paint):
                    return False
        return True
