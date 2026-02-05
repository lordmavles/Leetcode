class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        results = [None] * len(nums)
        for i in range(len(nums)):
            results[i] = nums[(i + nums[i] + 100 * len(nums)) % len(nums)]
        return results
