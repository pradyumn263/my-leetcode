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
    void flatten(TreeNode* root) {
        root = traverse(root);
    }
    
    TreeNode* traverse(TreeNode* root) {
        if (!root)
            return nullptr;
        
        TreeNode *temp = traverse(root->left);
        if (!temp) {
            root->right = traverse(root->right);
        } else {
            while(temp && temp->right)
                temp = temp->right;
            temp->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        
            temp->right = traverse(temp->right);
        }    
        return root;
        
    }
};