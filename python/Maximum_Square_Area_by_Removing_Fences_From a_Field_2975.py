import numpy as np

class Solution:

    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        hFences.extend([1, m])
        hFences.sort()
        vFences.extend([1, n])
        vFences.sort()
        hDists = np.zeros(((len(hFences) * (len(hFences) - 1)) // 2), dtype = np.int32)
        vDists = np.zeros(((len(vFences) * (len(vFences) - 1)) // 2), dtype = np.int32)
        idx = 0
        for i, curFence in enumerate(hFences):
            for j in range(i + 1, len(hFences)):
                hDists[idx] = hFences[j] - curFence
                idx += 1
        idx = 0
        for i, curFence in enumerate(vFences):
            for j in range(i + 1, len(vFences)):
                vDists[idx] = vFences[j] - curFence
                idx += 1
        hDists.sort()
        vDists.sort()
        MOD = 10**9 + 7
        for dist in reversed(hDists):
            targetInd = bisect_left(vDists, dist)
            if targetInd < len(vDists) and vDists[targetInd] == dist:
                return int(dist) * int(dist) % MOD
        return -1
