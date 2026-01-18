class Solution {
public:

    int largestMagicSquare(vector<vector<int>>& grid) {

        vector <vector <int>> horSum = grid, verSum = grid;
        for (int j = 1; j < horSum[0].size(); j++) {
            for (int i = 0; i < horSum.size(); i++) {
                horSum[i][j] += horSum[i][j - 1];
            }
        }
        for (int i = 1; i < verSum.size(); i++) {
            for (int j = 0; j < verSum[i].size(); j++) {
                verSum[i][j] += verSum[i - 1][j];
            }
        }

        int curMax = 1;

        for (int sqrSize = min(grid.size(), grid[0].size()); sqrSize > 1; sqrSize--) {
            for (int i = 0; i + sqrSize - 1 < grid.size(); i++) {
                for (int j = 0; j + sqrSize - 1 < grid[i].size(); j++) {
                    int matchSum = (horSum[i][j + sqrSize - 1] - (j > 0 ? horSum[i][j - 1] : 0));
                    int leftDiag = 0, rightDiag = 0;
                    bool allSumsMatched = true;
                    for (int k = 0; k < sqrSize; k++) {
                        int horMatch = horSum[i + k][j + sqrSize - 1] - (j > 0 ? horSum[i + k][j - 1] : 0);
                        int verMatch = verSum[i + sqrSize - 1][j + k] - (i > 0 ? verSum[i - 1][j + k] : 0);
                        if (horMatch != matchSum || verMatch != matchSum) {
                            allSumsMatched = false;
                            break;
                        }
                        leftDiag += grid[i + k][j + k];
                        rightDiag += grid[i + k][j + sqrSize - 1 - k];
                    }
                    if (leftDiag != rightDiag || leftDiag != matchSum) continue;
                    if (allSumsMatched) curMax = max(curMax, sqrSize);
                }
            }
        }

        return curMax;

    }
};
