class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        kSmallest, rest = SortedList(nums[1:k]), SortedList()
        curSum, glbSum = sum(kSmallest), sum(kSmallest)
        l, r = 1, k

        while r < len(nums):
            if nums[r] < kSmallest[-1]:
                maxSmallest = kSmallest.pop()
                curSum -= maxSmallest
                rest.add(maxSmallest)
                kSmallest.add(nums[r])
                curSum += nums[r]
            else:
                rest.add(nums[r])
            if r - l > dist:
                if nums[l] <= kSmallest[-1] and nums[l] in kSmallest:
                    kSmallest.remove(nums[l])
                    curSum -= nums[l]
                    newVal = rest.pop(0)
                    kSmallest.add(newVal)
                    curSum += newVal
                else:
                    rest.remove(nums[l])
                l += 1
            r += 1
            glbSum = min(glbSum, curSum)
        
        return nums[0] + glbSum
