class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        for i, num in enumerate(nums):
            if nums[i] == 2:
                nums[i] = -1
                continue
            nums[i] -= ((num + 1) & ~num) >> 1
        return nums
