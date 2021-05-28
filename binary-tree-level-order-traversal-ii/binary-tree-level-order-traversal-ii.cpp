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
    void traverse(TreeNode* root, vector<vector<int>> &res, int level) {
        if (!root)
            return;
        res[res.size() - 1 - level].push_back(root->val);
        traverse(root->left, res, level+1);
        traverse(root->right, res, level+1);
    }
    
    int getHeight(TreeNode* root) {
        if (!root)
            return 0;
        
        int a = getHeight(root->left);
        int b = getHeight(root->right);
        
        return (max(a,b) + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {        
        int h = getHeight(root);
        vector<vector<int>> res(h);
        traverse(root, res, 0);
        return res;
    }
};