import sys
class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        matrix = [[sys.maxsize for i in range(n)] for j in range(n)]
        for i in edges:
            src = i[0]
            dest = i[1]
            wt = i[2]
            matrix[src][dest] = wt
            matrix[dest][src] = wt
        for i in range(n):
            for j in range(n):
                if i == j:
                    matrix[i][j] = 0
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k])
        totcnt = n
        node = -1
        for i in range(n):
            cnt = 0
            for j in range(n):
                if matrix[i][j] <= distanceThreshold:
                    cnt += 1
            if cnt <= totcnt:
                totcnt = cnt
                node = max(node, i)
        return node
