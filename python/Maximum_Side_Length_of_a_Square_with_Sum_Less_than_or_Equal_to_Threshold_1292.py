class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:

        for i in range(len(mat)):
            for j in range(len(mat[0])):
                mat[i][j] += (mat[i - 1][j] if i > 0 else 0) + (mat[i][j - 1] if j > 0 else 0) - (mat[i - 1][j - 1] if i > 0 and j > 0 else 0)
        
        def calcMinArea(side):
            minArea = 1e9
            for i in range(side - 1, len(mat)):
                for j in range(side - 1, len(mat[0])):
                    curArea = mat[i][j] - (mat[i - side][j] if i >= side else 0) - (mat[i][j - side] if j >= side else 0) + (mat[i - side][j - side] if i >= side and j >= side else 0)
                    minArea = min(minArea, curArea)
            return minArea
        
        left, right, mid = 0, min(len(mat), len(mat[0])), 0
        while True:
            mid = (left + right) // 2
            if right - left < 2:
                if calcMinArea(right) <= threshold:
                    return right
                return left
            if calcMinArea(mid) > threshold:
                right = mid
            else:
                left = mid
        
        return -1
