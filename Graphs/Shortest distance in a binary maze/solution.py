#User function Template for python3

from typing import List
from queue import Queue
import sys
class Solution:
    
    def shortestPath(self, grid: List[List[int]], source: List[int], destination: List[int]) -> int:
        q = Queue()
        n = len(grid)
        m = len(grid[0])
        xdir = [-1,1,0,0]
        ydir = [0,0,-1,1]
        if source == destination:
            return 0
        distance = [[sys.maxsize for i in range(m)] for j in range(n)]
        q.put((source[0], source[1], 0))
        distance[source[0]][source[1]] = 0
        while not q.empty():
            x = q.get()
            for i in range(4):
                newx = x[0] + xdir[i]
                newy = x[1] + ydir[i]
                if newx >= 0 and newx < n and newy >= 0 and newy < m and grid[newx][newy] == 1:
                    if distance[newx][newy] > 1 + x[2]:
                        distance[newx][newy] = 1 + x[2]
                        if newx == destination[0] and newy == destination[1]:
                            return distance[newx][newy]
                        q.put((newx, newy,  distance[newx][newy]))
                    
        return -1
                
            
        
