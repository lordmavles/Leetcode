import numpy as np

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        horSum = np.array(grid)
        verSum = np.array(grid)

        for j in range(1, len(horSum[0])):
            for i in range(len(horSum)):
                horSum[i, j] += horSum[i, j - 1]
        
        for i in range(1, len(verSum)):
            for j in range(len(verSum[0])):
                verSum[i, j] += verSum[i - 1, j]

        curMax = 1
        
        for sqrSize in range(min(len(grid), len(grid[0])), 1, -1):
            for i in range(len(grid) - sqrSize + 1):
                for j in range(len(grid[0]) - sqrSize + 1):
                    matchSum = horSum[i, j + sqrSize - 1] - (horSum[i, j - 1] if j > 0 else 0)
                    leftDiag, rightDiag = 0, 0
                    allSumsMatched = True
                    for k in range(sqrSize):
                        horMatch = horSum[i + k, j + sqrSize - 1] - (horSum[i + k, j - 1] if j > 0 else 0)
                        verMatch = verSum[i + sqrSize - 1, j + k] - (verSum[i - 1, j + k] if i > 0 else 0)
                        if horMatch != matchSum or verMatch != matchSum:
                            allSumsMatched = False
                            break
                        leftDiag += grid[i + k][j + k]
                        rightDiag += grid[i + k][j + sqrSize - 1 - k]
                    if not allSumsMatched:
                        continue
                    if leftDiag == rightDiag and leftDiag == matchSum:
                        curMax = max(curMax, sqrSize)
        
        return curMax
