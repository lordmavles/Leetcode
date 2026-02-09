class Solution {
public:

    void storeInOrder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        storeInOrder(root->left, nodes);
        nodes.push_back(root);
        storeInOrder(root->right, nodes);
    }

    TreeNode* buildBST(vector <TreeNode*>& nodes, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = nodes[mid];
        root->left = buildBST(nodes, start, mid - 1);
        root->right = buildBST(nodes, mid + 1, end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector <TreeNode*> nodes;
        storeInOrder(root, nodes);
        return buildBST(nodes, 0, nodes.size() - 1);
    }
};
