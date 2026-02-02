class Solution {
public:

    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long glbSum = 0LL, curSum = 0LL;
        multiset <int> kSmallest;
        multiset <int> rest;
        for (int i = 1; i < k; i++) {
            curSum += nums[i];
            kSmallest.insert(nums[i]);
        }
        glbSum = curSum;
        int l = 1, r = k;
        while (r < nums.size()) {
            auto itMin = prev(kSmallest.end());
            if (nums[r] < *itMin) {
                rest.insert(*itMin);
                curSum -= *itMin;
                kSmallest.erase(itMin);
                kSmallest.insert(nums[r]);
                curSum += nums[r];
            }
            else {
                rest.insert(nums[r]);
            }
            if (r - l > dist) {
                if (kSmallest.find(nums[l]) != kSmallest.end()) {
                    auto itNum = kSmallest.find(nums[l]);
                    curSum -= nums[l];
                    kSmallest.erase(itNum);
                    auto itSmallest = rest.begin();
                    curSum += *itSmallest;
                    kSmallest.insert(*itSmallest);
                    rest.erase(itSmallest);
                }
                else {
                    rest.erase(rest.find(nums[l]));
                }
                l++;
            }
            r++;
            glbSum = min(glbSum, curSum);
        }
        return nums[0] + glbSum;
    }
};
