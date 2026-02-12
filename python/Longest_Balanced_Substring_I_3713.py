class Solution:
    def longestBalanced(self, s: str) -> int:
        maxWindow = 0
        for i in range(len(s)):
            frequency = [0] * 26
            for j in range(i, len(s)):
                frequency[ord(s[j]) - ord('a')] += 1
                minCount, maxCount = 1e9, 0
                for freq in frequency:
                    if freq > 0:
                        minCount = min(minCount, freq)
                        maxCount = max(maxCount, freq)
                if minCount == maxCount:
                    maxWindow = max(maxWindow, j - i + 1)
        return maxWindow
