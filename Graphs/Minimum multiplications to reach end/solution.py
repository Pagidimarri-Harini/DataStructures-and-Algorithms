

from typing import List
import sys
from queue import Queue
class Solution:
    
    def minimumMultiplications(self, arr : List[int], start : int, end : int) -> int:
        # code here
        distance = [sys.maxsize]*100000
        q = Queue()
        q.put((start,0))
        while not q.empty():
            x = q.get()
            for i in arr:
                num = (x[0]*i)%100000
                if x[1] + 1 < distance[num]:
                    distance[num] = x[1] + 1
                    if num == end:
                        return distance[num]
                    q.put((num, x[1]+1))
        return -1
