#Time complexity: O(n**2) for avg and worst cases and O(n) for best case
class Solution:
    def insert(self, arr, index, n):
        while index > 0 and arr[index-1] > arr[index]:
            arr[index], arr[index-1] = arr[index-1], arr[index]
            index -= 1

    def insertionSort(self, arr, n):
        for i in range(n):
            self.insert(arr, i, n)
        return arr
            
