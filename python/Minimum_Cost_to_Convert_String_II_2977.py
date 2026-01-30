class Solution:

    class Trie:

        counter = 0

        def __init__(self):
            self.child = [None] * 26
            self.id = -1
        
        def insert(self, curStr):
            cur = self
            for curChar in curStr:
                curId = ord(curChar) - ord('a')
                if not cur.child[curId]:
                    cur.child[curId] = Solution.Trie()
                cur = cur.child[curId]
            if cur.id == -1:
                cur.id = Solution.Trie.counter
                Solution.Trie.counter += 1
        
        def getNode(self, curStr):
            cur = self
            for curChar in curStr:
                curId = ord(curChar) - ord('a')
                if not cur.child[curId]:
                    return None
                cur = cur.child[curId]
            return cur
        
        def getId(self, curStr):
            cur = self.getNode(curStr)
            return (cur.id if cur else -1)


    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        
        inf = 10 ** 15
        self.Trie.counter = 0
        root = self.Trie()

        for curStr in original:
            root.insert(curStr)
        for curStr in changed:
            root.insert(curStr)
        
        edgeMatrix = [[inf] * self.Trie.counter for _ in range(self.Trie.counter)]
        for i in range(self.Trie.counter):
            edgeMatrix[i][i] = 0
        for orgStr, tarStr, curCost in zip(original, changed, cost):
            u, v = root.getId(orgStr), root.getId(tarStr)
            edgeMatrix[u][v] = min(edgeMatrix[u][v], curCost)
        for k in range(self.Trie.counter):
            for i in range(self.Trie.counter):
                if edgeMatrix[i][k] == inf:
                    continue
                for j in range(self.Trie.counter):
                    if edgeMatrix[k][j] != inf:
                        edgeMatrix[i][j] = min(edgeMatrix[i][j], edgeMatrix[i][k] + edgeMatrix[k][j])

        memTable = [inf] * len(source)
        for i in range(len(source) - 1, -1, -1):
            if source[i] == target[i]:
                memTable[i] = min(memTable[i], 0 if i == len(source) - 1 else memTable[i + 1])
            curSrc, curTar = root, root
            for j in range(i, len(source)):
                srcChar, tarChar = source[j], target[j]
                srcId, tarId = ord(srcChar) - ord('a'), ord(tarChar) - ord('a')
                if not curSrc.child[srcId] or not curTar.child[tarId]:
                    break
                curSrc, curTar = curSrc.child[srcId], curTar.child[tarId]
                if curSrc.id != -1 and curTar.id != -1:
                    nextCost = 0 if j == len(source) - 1 else memTable[j + 1]
                    if edgeMatrix[curSrc.id][curTar.id] != inf and nextCost != inf:
                        memTable[i] = min(memTable[i], edgeMatrix[curSrc.id][curTar.id] + nextCost)
        
        return memTable[0] if memTable[0] != inf else -1
