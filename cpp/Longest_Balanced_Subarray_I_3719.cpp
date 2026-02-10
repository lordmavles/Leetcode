class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxWindow = 0;
        for (int i = 0; i < nums.size(); i++) {
            set <int> odd, even;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] & 1) odd.insert(nums[j]);
                else even.insert(nums[j]);
                if (odd.size() == even.size()) maxWindow = max(maxWindow, j -i + 1);
            }
        }
        return maxWindow;
    }
};
