class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        maxPair = 0
        for i in range(len(nums) // 2):
            maxPair = max(maxPair, nums[i] + nums[-i-1])
        return maxPair
