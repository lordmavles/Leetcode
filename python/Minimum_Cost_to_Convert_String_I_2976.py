class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        edgeMatrix = [[1e17 for _ in range(26)] for _ in range(26)]
        
        for i in range(26):
            edgeMatrix[i][i] = 0

        for i in range(len(original)):
            u, v = ord(original[i]) - ord('a'), ord(changed[i]) - ord('a')
            edgeMatrix[u][v] = min(edgeMatrix[u][v], cost[i])

        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if edgeMatrix[i][k] + edgeMatrix[k][j] < edgeMatrix[i][j]:
                        edgeMatrix[i][j] = edgeMatrix[i][k] + edgeMatrix[k][j]

        minCost = 0
        for i in range(len(source)):
            u, v = ord(source[i]) - ord('a'), ord(target[i]) - ord('a')
            if edgeMatrix[u][v] == 1e17:
                return -1
            minCost += edgeMatrix[u][v]

        return minCost
