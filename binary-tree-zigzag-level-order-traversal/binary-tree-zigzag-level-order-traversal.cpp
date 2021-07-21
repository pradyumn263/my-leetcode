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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> res;
        traverse(root, res, 0);
        for (int i = 1; i < res.size(); i+=2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
    
    void traverse(TreeNode* root, vector<vector<int>> &res, int level) {
        if (!root)
            return;
        
        if (level == res.size())
            res.push_back({});
        
        res[level].push_back(root->val);
        traverse(root->left, res, level+1);
        traverse(root->right, res, level+1);
    }
};