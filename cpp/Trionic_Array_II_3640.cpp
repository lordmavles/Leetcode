class Solution {
public:

    static constexpr long long inf = 1e15;

    enum State {Up, Down, Equal};

    struct Store {
        int start;
        int end;
        State state;
        long long getPrefixSum(vector <int>& nums) {
            long long tot = 0LL, sum = -inf;
            for (int i = start; i <= end; i++) {
                tot += nums[i];
                if (i > start) {
                    sum = max(tot, sum);
                }
            }
            return sum;
        }
        long long getSuffixSum(vector <int>& nums) {
            long long tot = 0LL, sum = -inf;
            for (int i = end; i >= start; i--) {
                tot += nums[i];
                if (end > i) {
                    sum = max(tot, sum);
                }
            }
            return sum;
        }
        long long getSubarraySum(vector <int>& nums) {
            long long sum = 0LL;
            for (int i = start; i <= end; i++) {
                sum += nums[i];
            }
            return sum;
        }
    };

    long long maxSumTrionic(vector<int>& nums) {
        int prev = 0; State state = (nums[0] < nums[1] ? Up : (nums[0] > nums[1] ? Down : Equal));
        vector <Store> seq; seq.reserve(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            if (state == Up) {
                if (nums[i] == nums[i - 1]) {
                    seq.emplace_back(prev, i - 1, state);
                    prev = i - 1;
                    state = Equal;
                }
                else if (nums[i] < nums[i - 1]) {
                    seq.emplace_back(prev, i - 1, state);
                    prev = i - 1;
                    state = Down;
                }
            }
            else if (state == Equal) {
                if (nums[i] > nums[i - 1]) {
                    seq.emplace_back(prev, i - 1, state);
                    prev = i - 1;
                    state = Up;
                }
                else if (nums[i] < nums[i - 1]) {
                    seq.emplace_back(prev, i - 1, state);
                    prev = i - 1;
                    state = Down;
                }
            }
            else {
                if (nums[i] == nums[i - 1]) {
                    seq.emplace_back(prev, i - 1, state);
                    prev = i - 1;
                    state = Equal;
                }
                else if (nums[i] > nums[i - 1]) {
                    seq.emplace_back(prev, i - 1, state);
                    prev = i - 1;
                    state = Up;
                }
            }
        }
        seq.emplace_back(prev, nums.size() - 1, state);
        long long globalSum = -inf;
        for (int i = 0; i + 2 < seq.size(); i++) {
            if (seq[i].state == Up && seq[i + 1].state == Down && seq[i + 2].state == Up) {
                long long curSum = seq[i].getSuffixSum(nums) + seq[i + 1].getSubarraySum(nums) + seq[i + 2].getPrefixSum(nums) - nums[seq[i].end] * 1LL - nums[seq[i + 1].end] * 1LL;
                globalSum = max(globalSum, curSum);
            }
        }
        return globalSum;
    }
};
