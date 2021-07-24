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
    
    unordered_map<int, int> freq;
    int maxFreq = 0;
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        helper(root);
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second == maxFreq)
                res.push_back(it->first);
        }
        return res;
    }
    
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int leftSum = helper(root->left);
        int rightSum = helper(root->right);
        
        int sum = leftSum + root->val + rightSum;
        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);
        return sum;
    }
};