class Solution {
public:

    int minimumPairRemoval(vector<int>& nums) {
        int iter = 0;
        int numSize = nums.size();
        bool nonDecr = false;
        while (!nonDecr) {
            int minPair = 0;
            for (int i = 0; i < numSize - 1; i++) {
                if (nums[i] + nums[i + 1] < nums[minPair] + nums[minPair + 1]) minPair = i;
            }
            nonDecr = true;
            for (int i = 0; i < numSize - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    nonDecr = false;
                    iter += 1;
                    nums[minPair] += nums[minPair + 1];
                    for (int j = minPair + 1; j < numSize - 1; j++) {
                        nums[j] = nums[j + 1];
                    }
                    numSize--;
                    break;
                }
            }
        }
        return iter;
    }
};
