class Solution:
    def __init__(self):
        self.xdir = [1,-1,0,0]
        self.ydir = [0,0,1,-1]
    def dfs(self, i,j, grid):
        if i < 0 or i >= len(grid) or j < 0 or j >= len(grid[0]) or grid[i][j] == "0":
            return
        grid[i][j] = "0"
        for dir in range(4):
            ni = i + self.xdir[dir]
            nj = j + self.ydir[dir]
            if ni >= 0 and ni < len(grid) and nj >= 0 and nj < len(grid[0]) and grid[ni][nj] == "1":
                self.dfs(ni, nj,grid)
        return

    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    count += 1
                    self.dfs(i,j,grid)
        return count
