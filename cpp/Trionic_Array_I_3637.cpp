class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums[0] >= nums[1]) return false; 
        enum State {Up, Down, Up2};
        State state = Up;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return false;
            if (state == Up) {
                if (nums[i] < nums[i - 1]) state = Down;
            }
            else if (state == Down) {
                if (nums[i] > nums[i - 1]) state = Up2;
            }
            else {
                if (nums[i] < nums[i - 1]) return false;
            }
        }
        return (state == Up2);
    }
};
