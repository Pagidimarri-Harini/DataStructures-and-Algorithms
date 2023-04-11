
from queue import PriorityQueue
import sys
class Solution:
    def shortestPath(self, n, m, edges):
        adj = [[] for i in range(n+1)]
        for ad in edges:
            adj[ad[0]].append((ad[1], ad[2]));
            adj[ad[1]].append((ad[0], ad[2]));
        pq = PriorityQueue()
        distance = [sys.maxsize]*(n+1)
        parent = [i for i in range(n+1)]
        distance[1] = 0
        pq.put((0,1));
        while not pq.empty():
            x = pq.get();
            for ad in adj[x[1]]:
                if distance[ad[0]] > distance[x[1]] + ad[1]:
                    distance[ad[0]] = distance[x[1]] + ad[1]
                    parent[ad[0]] = x[1]
                    pq.put((distance[ad[0]],ad[0]))
        if distance[n] == sys.maxsize:
            return [-1]
        node = n
        ans = []
        while parent[node] != node:
            ans.append(node)
            node = parent[node]
        ans.append(1)
        ans = ans[::-1]
        return ans
