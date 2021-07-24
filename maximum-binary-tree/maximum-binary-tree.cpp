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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createTree(nums, 0, nums.size() - 1);
    }
    
    TreeNode* createTree(vector<int> &nums, int lo, int hi) {
        if (hi < lo || lo < 0 || hi > nums.size())
            return nullptr;
        
        if (hi == lo) {
            return new TreeNode(nums[lo]);
        }
        
        int maxElement = INT_MIN;
        int maxElementIndex = 0;
        
        for (int i = lo; i <= hi; i++) {
            if (nums[i] > maxElement) {
                maxElement = nums[i];
                maxElementIndex = i;
            }
        }
        
        TreeNode* root = new TreeNode(nums[maxElementIndex]);
        root->left = createTree(nums, lo, maxElementIndex-1);
        root->right = createTree(nums, maxElementIndex+1, hi);
        return root;
    }
};