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
    int rob(TreeNode* root) {
        int includingRoot = 0, notIncludingRoot = 0;
    
        includingRoot = findMoney(root, notIncludingRoot);
        return max(includingRoot, notIncludingRoot);
    }
    
    int findMoney(TreeNode *root, int &notIncludingThisNode) {
        if (!root) {
            notIncludingThisNode = 0;
            return 0;
        }
        
        int notIncludingLeft, notIncludingRight;
        int includingLeft = findMoney(root->left, notIncludingLeft);
        int includingRight = findMoney(root->right, notIncludingRight);
        
        notIncludingThisNode = max(notIncludingLeft, includingLeft) + max(notIncludingRight, includingRight);
        
        return root->val + notIncludingLeft + notIncludingRight;
    }
};