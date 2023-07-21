/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
        return nullptr;

    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* current = nodeQueue.front();
        nodeQueue.pop();

        if (current->val == val)
            return current;

        if (current->left)
            nodeQueue.push(current->left);

        if (current->right)
            nodeQueue.push(current->right);
    }

    return nullptr;
    }
};