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
        return nullptr;//agr root == null ha to nullptr return krdo

    std::queue<TreeNode*> nodeQueue;//ek queue bnayi nodeQueue naam ki
    nodeQueue.push(root);//push kra dia usme root node

    while (!nodeQueue.empty()) {//the while loop will continue running as long as the nodeQueue is not empty
       
        TreeNode* current = nodeQueue.front();// the current variable represents the node currently being processed during the level-order traversal of the binary search tree (BST)
        
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