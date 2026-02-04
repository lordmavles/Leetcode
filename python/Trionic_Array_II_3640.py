class Solution:

    class State:
        Up = 1
        Down = 2
        Equal = 3

    class Store:

        def __init__(self, start = None, end = None, state = None):
            self.start, self.end, self.state = start, end, state
        
        def getPrefixSum(self, nums):
            best, tot = -10**15, 0
            for i in range(self.start, self.end + 1):
                tot += nums[i]
                if i > self.start:
                    best = max(best, tot)
            return best
        
        def getSuffixSum(self, nums):
            best, tot = -10**15, 0
            for i in range(self.end, self.start - 1, -1):
                tot += nums[i]
                if i < self.end:
                    best = max(best, tot)
            return best
        
        def getSubarraySum(self, nums):
            return sum(nums[self.start : self.end + 1])

    def maxSumTrionic(self, nums: List[int]) -> int:
        
        prev, state = 0, (self.State.Up if nums[0] < nums[1] else (self.State.Down if nums[0] == nums[1] else self.State.Equal))
        seq = []

        for i in range(1, len(nums)):
            if state == self.State.Up:
                if nums[i] < nums[i - 1]:
                    seq.append(self.Store(prev, i - 1, state))
                    prev, state = i - 1, self.State.Down
                elif nums[i] == nums[i - 1]:
                    seq.append(self.Store(prev, i - 1, state))
                    prev, state = i - 1, self.State.Equal
            elif state == self.State.Equal:
                if nums[i] < nums[i - 1]:
                    seq.append(self.Store(prev, i - 1, state))
                    prev, state = i - 1, self.State.Down
                elif nums[i] > nums[i - 1]:
                    seq.append(self.Store(prev, i - 1, state))
                    prev, state = i - 1, self.State.Up
            else:
                if nums[i] == nums[i - 1]:
                    seq.append(self.Store(prev, i - 1, state))
                    prev, state = i - 1, self.State.Equal
                elif nums[i] > nums[i - 1]:
                    seq.append(self.Store(prev, i - 1, state))
                    prev, state = i - 1, self.State.Up
        seq.append(self.Store(prev, len(nums) - 1, state))

        glbSum = -10**15
        for i in range(len(seq) - 2):
            if seq[i].state == self.State.Up and seq[i + 1].state == self.State.Down and seq[i + 2].state == self.State.Up:
                curSum = seq[i].getSuffixSum(nums) + seq[i + 1].getSubarraySum(nums) + seq[i + 2].getPrefixSum(nums) - nums[seq[i].end] - nums[seq[i + 1].end]
                glbSum = max(glbSum, curSum)
        
        return glbSum
