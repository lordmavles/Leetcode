class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        maxArea = 0
        n = len(bottomLeft)
        for i in range(n):
            for j in range(i + 1, n):
                horSide = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0])
                verSide = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1])
                if horSide > 0 and verSide > 0:
                    maxArea = max(maxArea, min(horSide, verSide) ** 2)
        return maxArea
