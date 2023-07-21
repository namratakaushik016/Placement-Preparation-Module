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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        //Below function takes a reference to a vector of integers (preorder traversal of a binary search tree) as input and returns a pointer to the root of the constructed binary search tree.
         
        if(preorder.size() == 0) return NULL;
        
        //Three pointers are declared: root to store the root of the BST being constructed, pre to keep track of the previously visited node, and cur to traverse the tree during construction.
        
        TreeNode *root, *pre, *cur;
        
        //The first element of the preorder vector is used to create the root node of the BST.
        root = new TreeNode(preorder[0]);
        
        for(int i = 1; i < preorder.size(); i++){
            //- Starting from the second element of the preorder vector (index 1), we iterate through the rest of the elements.
            int p = preorder[i];
            cur = root;
            while(cur){
                // A while loop is initiated, which will continue as long as cur is not NULL.
                pre = cur;
                if(p < cur->val){
                    cur = cur->left;
                }else if(p >= cur->val){
                    cur = cur->right;
                }
            }
            if(p < pre->val){
                pre->left = new TreeNode(p);
            }else if(p >= pre->val){
                pre->right = new TreeNode(p);
            }
        }
        return root;
    }
};