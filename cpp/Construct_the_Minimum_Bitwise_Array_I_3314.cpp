class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& num: nums) {
            int ans = -1;
            if (num == 2) {
                num = -1;
                continue;
            }
            num -= (1 << __builtin_ctz(~num) - 1);
        }
        return nums;
    }
};
