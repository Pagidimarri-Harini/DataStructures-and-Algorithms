from queue import Queue
import sys
class Solution:
    def shortestPath(self, edges, n, m, src):
        adjlist=[[] for i in range(n)]
        for u,v in edges:
            adjlist[u].append(v)
            adjlist[v].append(u)

        distance=[sys.maxsize]*n
        distance[src]=0
        q=Queue()
        q.put(src)
        while not q.empty():
            node = q.get()
            for u in adjlist[node]:
                if distance[u]>distance[node]+1:
                    distance[u]=distance[node]+1
                    q.put(u)
        distance = [i if i != sys.maxsize else -1 for i in distance]
        return distance
