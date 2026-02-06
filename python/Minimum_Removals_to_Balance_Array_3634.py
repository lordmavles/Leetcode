class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        nums.sort()
        l, r, maxWindow = 0, 0, 0
        while r < len(nums):
            while nums[r] > k * nums[l]:
                l += 1
            maxWindow = max(maxWindow, r - l + 1)
            r += 1
        return len(nums) - maxWindow
