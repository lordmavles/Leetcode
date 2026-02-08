class Solution:

    def calcHeight(self, root):
        if not root:
            return 0
        leftHeight, rightHeight = self.calcHeight(root.left), self.calcHeight(root.right)
        if leftHeight == -1 or rightHeight == -1 or abs(leftHeight - rightHeight) > 1:
            return -1
        return 1 + max(leftHeight, rightHeight)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.calcHeight(root) != -1
