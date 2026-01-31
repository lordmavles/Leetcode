class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector <vector <long long>> edgeMatrix(26, vector <long long> (26, 1e17));
        for (int i = 0; i < 26; i++) edgeMatrix[i][i] = 0;
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            edgeMatrix[u][v] = min(edgeMatrix[u][v], static_cast<long long>(cost[i]));
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (edgeMatrix[i][k] + edgeMatrix[k][j] < edgeMatrix[i][j]) {
                        edgeMatrix[i][j] = edgeMatrix[i][k] + edgeMatrix[k][j];
                    }
                }
            }
        }
        long long minCost = 0;
        for (int i = 0; i < source.length(); i++) {
            if (edgeMatrix[source[i] - 'a'][target[i] - 'a'] == 1e17) return -1;
            else minCost += edgeMatrix[source[i] - 'a'][target[i] - 'a'];
        }
        return minCost;
    }
};
