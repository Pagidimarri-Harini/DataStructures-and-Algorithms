import sys
class Solution:
    def shortest_distance(self, matrix):
        n = len(matrix)
        for i in range(n):
            for j in range(n):
                if matrix[i][j] == -1:
                    matrix[i][j] = sys.maxsize
                if i == j:
                    matrix[i][j] = 0
        for i in range(n):
            for j in range(n):
                for k in range(n):
                    matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k])
        for i in range(n):
            for j in range(n):
                if matrix[i][j] == sys.maxsize:
                    matrix[i][j] = -1
        return matrix
