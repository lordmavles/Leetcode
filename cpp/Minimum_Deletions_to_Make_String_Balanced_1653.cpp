class Solution {
public:

    int minimumDeletions(string s) {
        int nextA = 0, nextB = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == 'a') {
                nextB += 1;
            }
            else {
                nextA = min(nextA + 1, nextB);
            }
        }
        return min(nextA, nextB);
    }
};
