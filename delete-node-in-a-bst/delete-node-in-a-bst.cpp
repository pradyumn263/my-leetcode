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
    
    TreeNode* getMin(TreeNode* root) {
        if (!root)
            return root;
        
        while(root->left)
            root = root->left;
        
        return root;
    }
    
    TreeNode* getMax(TreeNode* root) {
        if(!root)
            return root;
        
        while(root->right)
            root=root->right;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key) {
            if (root->left) {
                TreeNode* temp = getMax(root->left);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
                return root;
            } else if (root->right) {
                TreeNode* temp = getMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
                return root;
            } else return nullptr;
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        
        return root;
    }
};