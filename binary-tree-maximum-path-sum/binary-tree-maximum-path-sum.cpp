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
        if (!root->left && !root->right) 
            return root->val;
        
        int left = traverse(root->left);
        int right = traverse(root->right);
      
        res = max(res, root->val);
        if (root->right && root->left) {
            res = max(res, left);
            res = max(res, right);
            res = max(res, root->val + left + right);
            return max(root->val, root->val + max(left, right));
        } else if (root->right) {
            res = max(res, right);
            res = max(res, root->val + right);
            return max(root->val, root->val + right);
        } else {
            res = max(res, left);
            res = max(res, root->val + left);
            return max(root->val, root->val + left);
        }
       
        return root->val + max(left, right);
    }
};