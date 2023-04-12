from queue import PriorityQueue
class Solution:
    def minimumEffortPath(self, grid: List[List[int]]) -> int:
        q = PriorityQueue()
        n = len(grid)
        m = len(grid[0])
        xdir = [-1,1,0,0]
        ydir = [0,0,-1,1]
        distance = [[sys.maxsize for i in range(m)] for j in range(n)]
        q.put((0, 0, 0))
        distance[0][0] = 0
        while not q.empty():
            x = q.get()
            if x[1] == n-1 and x[2] == m-1:
                return x[0]
            for i in range(4):
                newx = x[1] + xdir[i]
                newy = x[2] + ydir[i]
                if newx >= 0 and newx < n and newy >= 0 and newy < m:
                    diff = max(x[0], abs(grid[newx][newy]- grid[x[1]][x[2]]))
                    if distance[newx][newy] > diff:
                        distance[newx][newy] = diff
                        q.put((distance[newx][newy],newx, newy))
