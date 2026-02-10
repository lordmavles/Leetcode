class Solution:
    def minimumDeletions(self, s: str) -> int:
        nextA, nextB = 0, 0
        for i in range(len(s) - 1, -1, -1):
            if s[i] == 'a':
                nextB += 1
            else:
                nextA = min(nextA + 1, nextB)
        return min(nextA, nextB)
