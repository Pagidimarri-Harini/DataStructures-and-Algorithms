from queue import Queue
class Solution:
    def topologicalSort(self, adjlist,K):
        q = Queue()
        indegree = [0 for i in range(K)]
        for i in adjlist:
            for j in i:
                indegree[j] += 1
        for i in range(K):
            if indegree[i] == 0:
                q.put(i)
        ans = []
        while not q.empty():
            x = q.get()
            ans.append(x)
            for i in adjlist[x]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    q.put(i)
        return ans
            
        
        return ans
    def findOrder(self,dict, N, K):
        adjlist = [[] for i in range(K)]
        for i in range(N-1):
            j = 0
            s1 = dict[i]
            s2 = dict[i+1]
            n = min(len(s1), len(s2))
            for j in range(n):
                if s1[j] != s2[j]:
                    adjlist[ord(dict[i][j])-97].append(ord(dict[i+1][j])-97)
                    break
        ans = self.topologicalSort(adjlist,K)
        res = ""
        for i in ans:
            res += chr(i+97)
        return res
