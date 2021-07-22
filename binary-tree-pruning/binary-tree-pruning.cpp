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
    TreeNode* pruneTree(TreeNode* root) {
        bool temp = false;
        root = traverse(root, temp);
        return root;
    }
    
    TreeNode* traverse(TreeNode* root, bool &containsOne) {
        if (!root) {
            containsOne = false;
            return root;
        }
        
        bool leftContainsOne = false, rightContainsOne = false;
        root->left = traverse(root->left, leftContainsOne);
        root->right = traverse(root->right, rightContainsOne);
        
        containsOne = leftContainsOne || rightContainsOne || (root->val == 1);
        
        if (!containsOne) {
            return nullptr;
        }
        return root;
    }
    
};