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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        traverse(root, 0, res);
        return res;
    }
    
    void traverse(TreeNode *root, int level, vector<int> &res) {
        if (!root)
            return;
        
        if (res.size() == level)
            res.push_back({});
        
        res[level] = root->val;
        traverse(root->left, level + 1, res);
        traverse(root->right, level + 1, res);
    }
};