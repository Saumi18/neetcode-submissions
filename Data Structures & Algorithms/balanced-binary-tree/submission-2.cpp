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
    bool decision = true;
    int heightOfTree(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = heightOfTree(root->left);
        int right = heightOfTree(root->right);

        if(abs(left-right) > 1) decision = false;
        
        return 1 + max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        heightOfTree(root);
        return decision;
    }
};
