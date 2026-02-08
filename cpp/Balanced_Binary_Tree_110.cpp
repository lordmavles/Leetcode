class Solution {
public:

    int calcHeight(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = calcHeight(root->left), rightHeight = calcHeight(root->right);
        if ((leftHeight == -1 || rightHeight == -1) or abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return calcHeight(root) != -1;
    }
};
