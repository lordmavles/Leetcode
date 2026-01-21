class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        for i, num in enumerate(nums):
            if num % 2 == 0:
                nums[i] = -1
            else:
                nums[i] -= ((num + 1) & ~num) >> 1
        return nums
