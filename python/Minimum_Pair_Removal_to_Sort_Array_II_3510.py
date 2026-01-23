class Node:
    def __init__(self):
        self.val = 0
        self.prev = -1
        self.next = -1

class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        iter = 0
        pool = [Node() for _ in range(len(nums))]

        for i in range(len(nums)):
            pool[i].val = nums[i]
            pool[i].prev = i - 1 if i > 0 else -1
            pool[i].next = i + 1 if i < len(nums) - 1 else -1
        
        nextMin = []
        invalidIndices = 0

        def isInvalid(i):
            if i == -1 or pool[i].next == -1:
                return False
            return pool[i].val > pool[pool[i].next].val
        
        for i in range(len(nums) - 1):
            if isInvalid(i):
                invalidIndices += 1
            heapq.heappush(nextMin, (pool[i].val + pool[i + 1].val, i))
        
        while invalidIndices > 0:
            curSum, curInd = heapq.heappop(nextMin)

            if pool[curInd].next == -1 or pool[curInd].val + pool[pool[curInd].next].val != curSum:
                continue
            
            prevInd = pool[curInd].prev
            nextInd = pool[curInd].next

            if isInvalid(curInd):
                invalidIndices -= 1
            if isInvalid(prevInd):
                invalidIndices -= 1
            if isInvalid(nextInd):
                invalidIndices -= 1
            
            pool[curInd].val += pool[nextInd].val

            if pool[nextInd].next != -1:
                pool[pool[nextInd].next].prev = curInd
                heapq.heappush(nextMin, (pool[curInd].val + pool[pool[nextInd].next].val, curInd))
            
            pool[curInd].next = pool[nextInd].next
            pool[nextInd].next = -1
            pool[nextInd].prev = -1

            if isInvalid(prevInd):
                invalidIndices += 1
            if isInvalid(curInd):
                invalidIndices += 1
            
            if prevInd != -1:
                heapq.heappush(nextMin, (pool[prevInd].val + pool[curInd].val, prevInd))
            
            iter += 1
        
        return iter
