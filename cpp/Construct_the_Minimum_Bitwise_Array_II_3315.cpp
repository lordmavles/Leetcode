class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& num: nums) {
            if (num % 2 == 0) num = -1;
            else num -= (1 << __builtin_ctz(~num) - 1);
        }
        return nums;
    }
};
