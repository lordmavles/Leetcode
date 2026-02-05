class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector <int> result; result.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(nums[(i + nums[i] + 100 * nums.size()) % nums.size()]);
        }
        return result;
    }
};
