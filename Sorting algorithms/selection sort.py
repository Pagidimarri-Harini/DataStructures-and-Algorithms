#Time complexity: O(n**2) in all cases
class Solution: 
    def select(self, arr, i):
        mini = i
        for j in range(i,n):
            if arr[mini] > arr[j]:
                mini = j
        return mini
    def selectionSort(self, arr,n):
        for i in range(n-1):
            mini = self.select(arr, i)
            arr[i], arr[mini] = arr[mini], arr[i]
        return arr
      
