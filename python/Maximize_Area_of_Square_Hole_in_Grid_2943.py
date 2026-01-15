class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        prevHInd, maxHCount = 0, 0
        hBars.sort()
        for ind, bar in enumerate(hBars):
            if hBars[ind] - hBars[prevHInd] == ind - prevHInd:
                maxHCount = max(maxHCount, ind - prevHInd + 1)
            else:
                prevHInd = ind
        prevVInd, maxVCount = 0, 0
        vBars.sort()
        for ind, bar in enumerate(vBars):
            if vBars[ind] - vBars[prevVInd] == ind - prevVInd:
                maxVCount = max(maxVCount, ind - prevVInd + 1)
            else:
                prevVInd = ind
        side = min(maxHCount, maxVCount) + 1
        return side ** 2
