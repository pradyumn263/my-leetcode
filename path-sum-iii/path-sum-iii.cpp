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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        unordered_map<int, int> mp;
        mp[0]++;
    
        int res = 0;
        traverse(root, 0, targetSum, res, mp);
        return res;
    }
    
    void traverse(TreeNode* root, int currSum, int targetSum, int &res, unordered_map<int,int> &mp) {
        if (!root)
            return;
        currSum += root->val;
        if (mp.find(currSum - targetSum) != mp.end()) {
            res += mp[currSum-targetSum];
        }
        
        mp[currSum]++;
        traverse(root->left, currSum, targetSum, res, mp);
        traverse(root->right, currSum, targetSum, res, mp);
        
        mp[currSum]--;
        
    }
};