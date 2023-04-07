class Solution:
    def dfs(self, node,visited, pathvisited, adjlist):
        visited[node] = 1
        pathvisited[node] = 1
        for i in adjlist[node]:
            if not visited[i]:
                if self.dfs(i, visited, pathvisited, adjlist):
                    return True
            elif pathvisited[i] == 1:
                return True
        pathvisited[node] = 0
        return False
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        visited = [0 for i in range(numCourses)]
        pathvisited = [0 for i in range(numCourses)]
        adjlist = [[] for i in range(numCourses)]
        for i in prerequisites:
            adjlist[i[1]].append(i[0])
        for i in range(numCourses):
            if not visited[i]:
                if self.dfs(i, visited, pathvisited, adjlist):
                    return False
        return True
