class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        
        vector <pair <int, int>> sortedCells;
        sortedCells.reserve(grid.size() * grid[0].size());

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                sortedCells.emplace_back(i, j);
            }
        }

        sort(sortedCells.begin(), sortedCells.end(), [&](pair <int, int> firstCell, pair <int, int> secondCell){
            return grid[firstCell.first][firstCell.second] < grid[secondCell.first][secondCell.second];
        });

        vector <vector <vector <int>>> gridCost(
            grid.size(), vector <vector <int>> (
                grid[0].size(), vector <int> (k + 1, 1e9)
            )
        );
        for (int i = 0; i <= k; i++) {
            gridCost[0][0][i] = 0;
        }

        for (int i = 0; i < gridCost.size(); i++) {
            for (int j = 0; j < gridCost[i].size(); j++) {
                if (i > 0) {
                    gridCost[i][j][0] = min(gridCost[i][j][0], grid[i][j] + gridCost[i - 1][j][0]);
                }
                if (j > 0) {
                    gridCost[i][j][0] = min(gridCost[i][j][0], grid[i][j] + gridCost[i][j - 1][0]);
                }
            }
        }

        for (int jump = 1; jump <= k; jump++) {
            int curMin = 1e9;
            for (int i = sortedCells.size() - 1; i >= 0; i--) {
                int j = i, curVal = grid[sortedCells[i].first][sortedCells[i].second];
                while (j >= 0 && grid[sortedCells[j].first][sortedCells[j].second] == curVal) {
                    curMin = min(curMin, gridCost[sortedCells[j].first][sortedCells[j].second][jump - 1]);
                    j--;
                }
                for (int l = i; l > j; l--) {
                    auto& [curX, curY] = sortedCells[l];
                    gridCost[curX][curY][jump] = curMin;
                }
                i = j + 1;
            }
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[i].size(); j++) {
                    if (i > 0) {
                        gridCost[i][j][jump] = min(gridCost[i][j][jump], gridCost[i - 1][j][jump] + grid[i][j]);
                    }
                    if (j > 0) {
                        gridCost[i][j][jump] = min(gridCost[i][j][jump], gridCost[i][j - 1][jump] + grid[i][j]);
                    }
                }
            }
        }

        return gridCost[grid.size() - 1][grid[0].size() - 1][k];

    }
};
