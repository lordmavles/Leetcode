class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        edgeList, nodeDepd = [[] for _ in range(n)], [[] for _ in range(n)]
        for edge in edges:
            edgeList[edge[0]].append([edge[1], edge[2]])
            nodeDepd[edge[1]].append([edge[0], edge[2]])
        nodeLens = [1e8 for _ in range(n)]
        nextEle = [(0, 0)]
        while nextEle:
            curDist, curNode = heapq.heappop(nextEle)
            if curDist > nodeLens[curNode]:
                continue
            for node, edgeLen in edgeList[curNode]:
                if nodeLens[node] > curDist + edgeLen:
                    nodeLens[node] = curDist + edgeLen
                    heapq.heappush(nextEle, (nodeLens[node], node))
            for node, edgeLen in nodeDepd[curNode]:
                if nodeLens[node] > curDist + 2 * edgeLen:
                    nodeLens[node] = curDist + 2 * edgeLen
                    heapq.heappush(nextEle, (nodeLens[node], node))
        return -1 if nodeLens[-1] is 1e8 else nodeLens[-1]

