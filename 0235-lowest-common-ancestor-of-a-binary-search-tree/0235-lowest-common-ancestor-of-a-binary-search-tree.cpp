/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if (root == nullptr) {
            return nullptr; // Base case: Empty tree or node not found
        }
        
        // If both p and q are smaller than the current node's value,
        // the LCA lies in the left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If both p and q are greater than the current node's value,
        // the LCA lies in the right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // If one node is smaller and the other is greater than the
        // current node's value, then the current node is the LCA
        return root;
    }
};