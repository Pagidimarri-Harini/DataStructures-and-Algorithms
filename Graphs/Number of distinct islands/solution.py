#User function Template for python3

import sys
from typing import List
sys.setrecursionlimit(10**8)
class Solution:
    def dfs(self,grid,start,end,i,j,n,m,ls):
        if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] == 0:
            return
        grid[i][j] = 0
        ls.append([i-start,j-end])
        self.dfs(grid,start,end,i+1,j,n,m,ls)
        self.dfs(grid,start,end,i-1,j,n,m,ls)
        self.dfs(grid,start,end,i,j-1,n,m,ls)
        self.dfs(grid,start,end,i,j+1,n,m,ls)
        
    def countDistinctIslands(self, grid : List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        x = set()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ls = []
                    self.dfs(grid,i,j,i,j,n,m,ls)
                    x.add(tuple(map(tuple, ls)))
        return len(x)
        # code here
