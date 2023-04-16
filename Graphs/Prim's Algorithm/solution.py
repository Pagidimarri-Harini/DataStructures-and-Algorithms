
import heapq
class Solution:
    def spanningTree(self, V, adj):
        q = [(0,0)]
        visited = [0]*V
        totwt = 0
        while q:
            x = heapq.heappop(q)
            wt = x[0]
            node = x[1]
            if visited[node] == 1:
                continue
            visited[node] = 1
            totwt += wt
            for i in adj[node]:
                if visited[i[0]] == 0:
                    heapq.heappush(q, (i[1], i[0]))
        return totwt 
