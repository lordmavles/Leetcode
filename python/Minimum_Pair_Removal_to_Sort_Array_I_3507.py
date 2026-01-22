class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        numsSize = len(nums)
        count = 0
        nonDecr = False
        while not nonDecr:
            minPair = 0;
            for i in range(numsSize - 1):
                if nums[i] + nums[i + 1] < nums[minPair] + nums[minPair + 1]:
                    minPair = i
            nonDecr = True
            for i in range(numsSize - 1):
                if nums[i] > nums[i + 1]:
                    nonDecr = False
                    count += 1
                    numsSize -= 1
                    nums[minPair] += nums[minPair + 1]
                    for j in range(minPair + 1, numsSize):
                        nums[j] = nums[j + 1]
                    break
        return count
