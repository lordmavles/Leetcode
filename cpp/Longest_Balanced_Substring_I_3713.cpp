class Solution {
public:
    int longestBalanced(string s) {
        int maxWindow = 0;
        for (int i = 0; i < s.length(); i++) {
            vector <int> frequency(26);
            for (int j = i; j < s.length(); j++) {
                frequency[s[j] - 'a']++;
                int minCount = 1e9, maxCount = 0;
                for (int k = 0; k < 26; k++) {
                    if (frequency[k] > 0) {
                        minCount = min(minCount, frequency[k]);
                        maxCount = max(maxCount, frequency[k]);
                    }
                }
                if (minCount == maxCount) {
                    maxWindow = max(maxWindow, j - i + 1);
                }
            }
        }
        return maxWindow;
    }
};
