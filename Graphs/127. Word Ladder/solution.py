from queue import Queue
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        s = set(wordList)
        alphabet = list(string.ascii_lowercase)
        distance = 1
        q = Queue()
        q.put(beginWord)
        if endWord not in s:
            return 0
        while not q.empty():
            z = q.qsize()
            flag = 0
            for k in range(z):
                x = q.get()
                for i in range(len(x)):
                    for j in alphabet:
                        word = x[:i] + j + x[i+1:]
                        if word in s:
                            if word == endWord:
                                return distance+1
                            flag = 1
                            q.put(word)
                            s.remove(word)
            if flag == 1:
                distance += 1
        return 0
                    
