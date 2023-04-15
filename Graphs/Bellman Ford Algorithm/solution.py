import sys
class Solution:
    def bellman_ford(self, V, edges, S):
        distance = [sys.maxsize]*V
        distance[S] = 0
        for i in range(V-1):
            for i in edges:
                src = i[0]
                dest = i[1]
                wt = i[2]
                distance[dest] = min(distance[dest],wt + distance[src])
        for i in edges:
            src = i[0]
            dest = i[1]
            wt = i[2]
            if distance[dest] > wt + distance[src]:
                return [-1]
        for i in range(V):
            if distance[i] == sys.maxsize:
                distance[i] = 100000000
        return distance
                
