class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        maxWindow = 0
        for i in range(len(nums)):
            odd, even = set(), set()
            for j in range(i, len(nums)):
                if nums[j] & 1:
                    odd.add(nums[j])
                else:
                    even.add(nums[j])
                if len(odd) == len(even):
                    maxWindow = max(maxWindow, j - i + 1)
        return maxWindow
