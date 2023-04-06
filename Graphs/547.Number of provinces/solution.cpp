class Solution:
    def dfs(self, start, adjlist, visited):
        visited[start] = 1
        for i in adjlist[start]:
            if visited[i] == 0:
                self.dfs(i,adjlist,visited)
        return

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        adjlist = [[] for i in range(len(isConnected))]
        for i in range(len(isConnected)):
            for j in range(len(isConnected)):
                if isConnected[i][j] == 1:
                    adjlist[i].append(j)
                    adjlist[j].append(i)
        nodes = len(adjlist)
        visited = [0 for i in range(nodes)]
        count = 0
        for i in range(nodes):
            if visited[i] == 0:
                self.dfs(i,adjlist,visited)
                count += 1
        return count
