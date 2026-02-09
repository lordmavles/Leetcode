class Solution:

    def storeInOrder(self, root, nodes):
        if not root:
            return
        self.storeInOrder(root.left, nodes)
        nodes.append(root)
        self.storeInOrder(root.right, nodes)

    def buildBST(self, nodes, start, end):
        if start > end:
            return None
        mid = (start + end) // 2
        root = nodes[mid]
        root.left = self.buildBST(nodes, start, mid - 1)
        root.right = self.buildBST(nodes, mid + 1, end)
        return root

    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        nodes = []
        self.storeInOrder(root, nodes)
        return self.buildBST(nodes, 0, len(nodes) - 1)
