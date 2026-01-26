class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        minDiff = int(1e9)
        diffArr = []
        arr.sort()
        for i in range(1, len(arr)):
            minDiff = min(minDiff, arr[i] - arr[i - 1])
        for i in range(1, len(arr)):
            if arr[i] - arr[i - 1] == minDiff:
                diffArr.append([arr[i - 1], arr[i]])
        return diffArr
