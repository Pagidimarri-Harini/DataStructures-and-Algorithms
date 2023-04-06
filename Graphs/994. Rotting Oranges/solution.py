from queue import Queue
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        xdir= [-1,0,1,0]
        ydir = [0, 1, 0,-1]
        n, m = len(grid), len(grid[0])
        q = Queue()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.put((i,j))
        count = 0
        while not q.empty():
            s = q.qsize()
            flag = 0
            for i in range(s):
                x = q.get()
                for d in range(4):
                    ni = x[0] + xdir[d]
                    nj = x[1] + ydir[d]
                    if ni >= 0 and ni < n and nj >=0 and nj < m and grid[ni][nj] == 1:
                        flag = 1
                        grid[ni][nj] = 2
                        q.put((ni, nj))
            if flag == 1:
                count += 1
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return -1
        return count


