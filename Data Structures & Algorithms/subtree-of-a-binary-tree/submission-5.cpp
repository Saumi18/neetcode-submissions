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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(sameTree(root,subRoot)) return true;
        return isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot);
    }
    bool sameTree(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(a && b && a->val == b->val){
            return sameTree(a->right,b->right) && sameTree(a->left,b->left);
        }
        return false;
    }
};
