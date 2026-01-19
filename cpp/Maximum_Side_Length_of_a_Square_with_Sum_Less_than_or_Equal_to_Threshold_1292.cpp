class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        for (int i = 1; i < mat.size(); i++) {
            mat[i][0] += mat[i - 1][0];
        }
        for (int i = 1; i < mat[0].size(); i++) {
            mat[0][i] += mat[0][i - 1];
        }
        for (int i = 1; i < mat.size(); i++) {
            for (int j = 1; j < mat[i].size(); j++) {
                mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
            }
        }

        auto calcMinArea = [&mat](int side) {
            int minArea = static_cast<int>(1e9);
            for (int i = side - 1; i < mat.size(); i++) {
                for (int j = side - 1; j < mat[i].size(); j++) {
                int curArea = mat[i][j] - (i >= side ? mat[i - side][j] : 0) - (j >= side ? mat[i][j - side] : 0) + (i >= side && j >= side ? mat[i - side][j - side] : 0);
                    minArea = min(minArea, curArea);
                }
            }
            return minArea;
        };

        int left = 0, right = min(mat.size(), mat[0].size()), mid;
        while (true) {
            mid = (left + right) / 2;
            if (right - left < 2) {
                if (calcMinArea(right) <= threshold) return right;
                return left;
            }
            if (calcMinArea(mid) > threshold) right = mid;
            else left = mid;
        }

        return -1;

    }
};
