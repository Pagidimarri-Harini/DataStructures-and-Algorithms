#Time complexity: O(n**2) for avg and worst cases, O(n) for best case
class Solution:
    def bubbleSort(self,arr, n):
        for i in range(n):
            swapped = 0
            for j in range(n-i-1):
                if arr[j+1] < arr[j]:
                    swapped = 1
                    arr[j+1], arr[j] = arr[j], arr[j+1]
            if swapped == 0:
                return arr
        return arr
