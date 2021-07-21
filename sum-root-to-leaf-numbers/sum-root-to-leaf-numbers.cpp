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
    int res = 0;
    
    int sumNumbers(TreeNode* root) {
        traverse(root, 0);
        return res;
    }
    
    void traverse(TreeNode* root, int currNum) {
        if (!root)
            return;
        currNum = currNum * 10 + root->val;
        if (!root->left && !root->right) {
            res += currNum;
            return;
        }
        
        traverse(root->left, currNum);
        traverse(root->right, currNum);
    }
};