class Solution {
public:

    static const int MOD = 1e9+7;

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector <int> horizontalDists, verticalDists;
        hFences.insert(hFences.end(), {1, m}), vFences.insert(vFences.end(), {1, n});
        horizontalDists.reserve(((hFences.size()) * (hFences.size() - 1)) / 2);
        verticalDists.reserve(((vFences.size()) * (vFences.size() - 1)) / 2);
        sort(hFences.begin(), hFences.end()), sort(vFences.begin(), vFences.end());
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                horizontalDists.push_back(hFences[j] - hFences[i]);
            }
        }
        sort(horizontalDists.begin(), horizontalDists.end());
        horizontalDists.erase(unique(horizontalDists.begin(), horizontalDists.end()), horizontalDists.end());
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                verticalDists.push_back(vFences[j] - vFences[i]);
            }
        }
        sort(verticalDists.begin(), verticalDists.end());
        verticalDists.erase(unique(verticalDists.begin(), verticalDists.end()), verticalDists.end());
        for (int i = horizontalDists.size() - 1; i >= 0; i--) {
            auto closestVerticalDist = lower_bound(verticalDists.begin(), verticalDists.end(), horizontalDists[i]);
            if (closestVerticalDist != verticalDists.end() && *closestVerticalDist == horizontalDists[i]) {
                return static_cast<int>((horizontalDists[i] * 1LL * horizontalDists[i]) % MOD);
            }
        }
        return -1;
    }
};
