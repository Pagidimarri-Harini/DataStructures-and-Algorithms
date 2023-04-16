import heapq
class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        q = [(0,(points[0][0], points[0][1]))]
        visited = {}
        totwt = 0
        while q:
            x = heapq.heappop(q)
            wt = x[0]
            node = x[1]
            if node in visited:
                continue
            visited[(node[0], node[1])] = 1
            totwt += wt
            dist = sys.maxsize
            for i in points:
                if (i[0], i[1]) not in visited:
                    heapq.heappush(q, ((abs(node[0]-i[0]) + abs(node[1]-i[1])), (i[0], i[1])))
        return totwt 

        
