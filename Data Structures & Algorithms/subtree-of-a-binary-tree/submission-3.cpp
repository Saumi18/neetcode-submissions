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
    void serialize(TreeNode* root, string& s) {
        if(root == NULL) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        serialize(root->left, s);
        serialize(root->right, s);
    }

    vector<int> buildLPS(string& pattern) {
        vector<int> lps(pattern.size(), 0);
        int len = 0;
        int i = 1;
        while(i < pattern.size()) {
            if(pattern[i] == pattern[len]) {
                lps[i] = ++len;
                i++;
            }
            else {
                if(len != 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool KMP(string& text, string& pattern) {
        vector<int> lps = buildLPS(pattern);
        int i = 0;
        int j = 0;
        while(i < text.size()) {
            if(text[i] == pattern[j]) {
                i++;
                j++;
                if(j == pattern.size())
                    return true;
            }
            else {
                if(j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        string rootString = "";
        string subString = "";
        serialize(root, rootString);
        serialize(subRoot, subString);
        return KMP(rootString, subString);
    }
};