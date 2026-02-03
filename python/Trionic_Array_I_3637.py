class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        if nums[0] >= nums[1]:
            return False
        
        Up, Down, Up2 = 0, 1, 2
        state = Up
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1]:
                return False
            if state == Up:
                if nums[i] < nums[i - 1]:
                    state = Down
            elif state == Down:
                if nums[i] > nums[i - 1]:
                    state = Up2
            else:
                if nums[i] < nums[i - 1]:
                    return False
        
        return state == Up2
