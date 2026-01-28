class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        sortedCells = []
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                sortedCells.append((i, j))
        
        sortedCells.sort(key = lambda cell: grid[cell[0]][cell[1]])

        gridCost = [
            [
                [10 ** 9 for _ in range(k + 1)]
                for _ in range(len(grid[0]))
            ]
            for _ in range(len(grid))
        ]

        for i in range(k + 1):
            gridCost[0][0][i] = 0
        
        for i in range(len(gridCost)):
            for j in range(len(gridCost[i])):
                if i > 0:
                    gridCost[i][j][0] = min(gridCost[i][j][0], grid[i][j] + gridCost[i - 1][j][0])
                if j > 0:
                    gridCost[i][j][0] = min(gridCost[i][j][0], grid[i][j] + gridCost[i][j - 1][0])
        
        for jump in range(1, k + 1):
            curMin = 10 ** 9
            i = len(sortedCells) - 1
            while i >= 0:
                j, curVal = i, grid[sortedCells[i][0]][sortedCells[i][1]]
                while j >= 0 and grid[sortedCells[j][0]][sortedCells[j][1]] == curVal:
                    curMin = min(curMin, gridCost[sortedCells[j][0]][sortedCells[j][1]][jump - 1])
                    j -= 1
                for l in range(i, j, -1):
                    curX, curY = sortedCells[l]
                    gridCost[curX][curY][jump] = curMin
                i = j
            for i in range(len(grid)):
                for j in range(len(grid[i])):
                    if i > 0:
                        gridCost[i][j][jump] = min(gridCost[i][j][jump], gridCost[i - 1][j][jump] + grid[i][j])
                    if j > 0:
                        gridCost[i][j][jump] = min(gridCost[i][j][jump], gridCost[i][j - 1][jump] + grid[i][j])
        
        return gridCost[len(grid) - 1][len(grid[0]) - 1][k]
