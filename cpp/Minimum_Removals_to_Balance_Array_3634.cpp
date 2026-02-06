class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, maxWindow = 0;
        while (r < nums.size()) {
            while (static_cast<long long>(nums[r]) > static_cast<long long>(k) * nums[l]) l++;
            maxWindow = max(maxWindow, r - l + 1);
            r++;
        }
        return nums.size() - maxWindow;
    }
};
