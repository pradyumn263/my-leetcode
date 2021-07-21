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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> currSet;
        traverse(root, currSet, res, targetSum);
        return res;
    }
    
    void traverse(TreeNode* root, vector<int> &currSet, vector<vector<int>> &res, int currSum) {
        if (!root)
            return;
        currSet.push_back(root->val);
        currSum -= root->val;
        if (!root->left && !root->right) {
            if (currSum == 0) {
                res.push_back(currSet);
            }
        }
        
        traverse(root->left, currSet, res, currSum);
        traverse(root->right, currSet, res, currSum);
        
        currSet.pop_back();
        currSum += root->val;
    }
};