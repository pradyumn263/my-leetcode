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
    int maxAncestorDiff(TreeNode* root) {
        int max = 0, min = 0;
        return helper(root, max, min);
        
    }
    
    int helper(TreeNode* root, int &subtreeMax, int &subtreeMin) {
        if (!root) {
            subtreeMax = 0;
            subtreeMin = 0;
            return 0;
        }
        
        int leftMax, leftMin, rightMax, rightMin;
        int leftDiff = helper(root->left, leftMax, leftMin);
        int rightDiff = helper(root->right, rightMax, rightMin);
        

        if (!root->left && !root->right) {
            subtreeMax = root->val;
            subtreeMin = root->val;
            return 0;
        }
        
        if (!root->left) {
            subtreeMax = max(root->val, rightMax);
            subtreeMin = min(root->val, rightMin);
            return max(rightDiff, max(abs(rightMax - root->val), abs(rightMin - root->val)));
        }
        
        if (!root->right) {
            subtreeMax = max(root->val, leftMax);
            subtreeMin = min(root->val, leftMin);
            return max(leftDiff, max(abs(leftMax - root->val), abs(leftMin - root->val)));
        }

        subtreeMax = max(root->val, max(leftMax, rightMax));
        subtreeMin = min(root->val, min(leftMin, rightMin));
        int maxDiff = max(leftDiff, rightDiff);
        
        return max(maxDiff, max(max(abs(root->val - leftMax), abs(root->val - leftMin)), max(abs(root->val - rightMax), abs(root->val - rightMin))));
        
    }
};