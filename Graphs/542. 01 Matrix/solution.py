from queue import Queue
class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        xdir = [0,0,1,-1]
        ydir = [1,-1,0,0]
        n = len(mat)
        m = len(mat[0])
        ls = [[0 for i in range(m)] for j in range(n)]
        visited = [[0 for i in range(m)] for j in range(n)]
        q = Queue()
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    q.put((i,j))
                    visited[i][j] = 1
        distance = 0
        while not q.empty():
            z = q.qsize()
            for i in range(z):
                x = q.get()
                ls[x[0]][x[1]] = distance
                for j in range(4):
                    ni = x[0] + xdir[j]
                    nj = x[1] + ydir[j]
                    if ni >= 0 and ni < n and nj >= 0 and nj < m and visited[ni][nj] == 0:
                        q.put((ni,nj))
                        visited[ni][nj] = 1
            distance += 1
        return ls
