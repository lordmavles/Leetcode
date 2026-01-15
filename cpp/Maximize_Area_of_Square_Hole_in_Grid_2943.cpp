class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        int prevHInd = 0, maxHCont = 0;
        for (int i = 0; i < hBars.size(); i++) {
            if (hBars[i] - hBars[prevHInd] == i - prevHInd) {
                maxHCont = max(maxHCont, i - prevHInd + 1);
                continue;
            }
            else {
                prevHInd = i;
            }
        }
        sort(vBars.begin(), vBars.end());
        int prevVInd= 0, maxVCont = 0;
        for (int i = 0; i < vBars.size(); i++) {
            if (vBars[i] - vBars[prevVInd] == i - prevVInd) {
                maxVCont = max(maxVCont, i - prevVInd + 1);
                continue;
            }
            else {
                prevVInd = i;
            }
        }
        int side = min(maxHCont, maxVCont) + 1;
        return side * side;
    }
};
