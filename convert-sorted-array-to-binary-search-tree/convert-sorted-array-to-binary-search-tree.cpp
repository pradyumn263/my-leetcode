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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return treeHelper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* treeHelper(vector<int> &nums, int lo, int hi) {
        if (lo < 0 || hi > nums.size() || hi < lo)
            return nullptr;
        
        if (hi == lo) {
            return new TreeNode(nums[lo]);
        }
        
        int mid = lo + (hi - lo)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = treeHelper(nums, lo, mid-1);
        root->right = treeHelper(nums, mid+1, hi);
        return root;
    }
};