class Node {
public:
    long long val;
    int next;
    int prev;
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int iter = 0;

        vector <Node> pool(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            pool[i].val = nums[i];
            pool[i].prev = (i > 0 ? i - 1 : -1);
            pool[i].next = (i < nums.size() - 1 ? i + 1 : -1);
        }

        priority_queue <pair <long long, int>, vector <pair <long long, int>>, greater <pair <long long, int>>> nextMin;
        int invalidIndices = 0;

        auto isInvalid = [&](int i) {
            if (i == -1 || pool[i].next == -1) return false;
            return pool[i].val > pool[pool[i].next].val;
        };

        for (int i = 0; i < nums.size() - 1; i++) {
            if (isInvalid(i)) invalidIndices++;
            nextMin.emplace(pool[i].val + pool[i + 1].val, i);
        }

        while (invalidIndices > 0) {
            auto [curSum, curInd] = nextMin.top();
            nextMin.pop();
            if (pool[curInd].next == -1 || pool[curInd].val + pool[pool[curInd].next].val != curSum) continue;
            
            int prevInd = pool[curInd].prev, nextInd = pool[curInd].next;
            
            if (isInvalid(prevInd)) invalidIndices--;
            if (isInvalid(curInd)) invalidIndices--;
            if (isInvalid(nextInd)) invalidIndices--;

            pool[curInd].val += pool[nextInd].val;
            if (pool[nextInd].next != -1) {
                pool[pool[nextInd].next].prev = curInd;
                nextMin.emplace(pool[curInd].val + pool[pool[nextInd].next].val, curInd);
            }
            pool[curInd].next = pool[nextInd].next;
            pool[nextInd].next = -1;
            pool[nextInd].prev = -1;

            if (isInvalid(prevInd)) invalidIndices++;
            if (isInvalid(curInd)) invalidIndices++;
            
            if (prevInd != -1) nextMin.emplace(pool[prevInd].val + pool[curInd].val, prevInd);
            iter++;
        }

        return iter;
    }
};
