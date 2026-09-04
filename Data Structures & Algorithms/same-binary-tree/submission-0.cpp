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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool leftDec = true;
        bool rightDec = true;
        if(p!=NULL && q!=NULL && p->val != q->val) return false;
        if((p!=NULL && q==NULL) || (p==NULL && q!=NULL)) return false;
        if(p==NULL && q == NULL) return true;
        rightDec = isSameTree(p->right,q->right);
        leftDec = isSameTree(p->left,q->left);
        return (leftDec)&&(rightDec);
    }
};
