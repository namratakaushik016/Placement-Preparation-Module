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
    bool isValidBST(TreeNode* root) {
       return isValidBSTHelper(root, LONG_MIN, LONG_MAX);                 
    }
    
    bool isValidBSTHelper(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) {
            return true;
        }
        
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
            //we check whether the value of the current node (node->val) is less than or equal to the minVal or greater than or equal to the maxVal. If either of these conditions is true, it means the current node's value violates the BST property, and we return false to indicate that this subtree is not a valid BST.
        }
        
        return isValidBSTHelper(node->left, minVal, node->val) &&
               isValidBSTHelper(node->right, node->val, maxVal);
        //The idea behind these checks is that the left subtree of a node must contain only nodes with keys less than the node's key, and the right subtree must contain only nodes with keys greater than the node's key.
    }
};
    