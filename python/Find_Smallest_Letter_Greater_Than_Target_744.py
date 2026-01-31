class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        id = bisect_right(letters, target)
        return letters[0] if id == len(letters) else letters[id]
