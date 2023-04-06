class Solution:
    def dfs(self,i,j,grid,n,m):
        if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 0:
            return
        grid[i][j] = 0
        self.dfs(i+1,j,grid,n,m)
        self.dfs(i-1,j,grid,n,m)
        self.dfs(i,j-1,grid,n,m)
        self.dfs(i,j+1,grid,n,m)
    def numEnclaves(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        x = set()
        for i in range(n):
            for j in range(m):
                if (i==0 or j==0 or i==n-1 or j==m-1) and grid[i][j] == 1:
                    self.dfs(i,j,grid,n,m)
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    count += 1
        return count
