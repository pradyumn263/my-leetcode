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
    
    int maxDepth = 0;
    TreeNode* res = nullptr;
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root)
            return nullptr;
        helper(root, 0);
        return res;
    }
    
    int helper(TreeNode* root, int depth) {
        if (!root)
            return 0;
        
        int leftDepth = helper(root->left, depth+1);
        int rightDepth = helper(root->right, depth+1);
        
        if (!root->right && !root->left) {
            if (depth >= maxDepth) {
                res = root;
                maxDepth = depth;
            }
            return depth;
        }
        
        if (leftDepth == rightDepth && leftDepth >= maxDepth) {
            res = root;
        }
        
        return max(leftDepth, rightDepth);
    }
};