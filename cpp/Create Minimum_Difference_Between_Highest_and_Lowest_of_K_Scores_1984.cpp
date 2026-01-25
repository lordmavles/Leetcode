class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int glbMin = 1e9;
        for (int i = 0; i + k - 1 < nums.size(); i++) {
            glbMin = min(glbMin, nums[i + k - 1] - nums[i]);
        }
        return glbMin;
    }
};
