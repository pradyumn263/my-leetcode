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
    int res = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        int temp = traverse(root);
        return max(temp, res);
    }
    
    int traverse(TreeNode* root) {
       if (!root)
           return 0;
        
        // We take max with 0, because if left or right are negative then no need to include them in any path as it will always decrease your sum
        int left = max(traverse(root->left), 0);
        int right = max(traverse(root->right), 0);
        res = max(res, root->val + left + right);
        
        return root->val + max(left, right);
    }
};