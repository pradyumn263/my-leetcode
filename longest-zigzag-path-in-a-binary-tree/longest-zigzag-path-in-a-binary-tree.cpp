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
    
    int longestZigZag(TreeNode* root) {
        int a = 0, b = 0;
        helper(root, a, b);
        return res;
    }
    
    void helper(TreeNode* root, int &leftFromNode, int &rightFromNode) {
        if (!root) {
            leftFromNode = 0;
            rightFromNode = 0;
            return;
        }
        
        int leftFromLeft, rightFromLeft, rightFromRight, leftFromRight;
        helper(root->left, leftFromLeft, rightFromLeft);
        helper(root->right, leftFromRight, rightFromRight);
        
        rightFromNode = leftFromRight != 0 ? 1 + leftFromRight : 0;
        leftFromNode = rightFromLeft != 0 ? 1 + rightFromLeft : 0;
        
        if (rightFromNode == 0 && root->right) {
            rightFromNode = 1;
        }
        
        if (leftFromNode == 0 && root->left) {
            leftFromNode = 1;
        }
        res = max(res, max(leftFromNode, rightFromNode));
        return;
    }
};