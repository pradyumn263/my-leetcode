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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (!root) {
            if (depth == 1) {
                return new TreeNode(val);
            }
            return nullptr;
        }
        
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        
        return traverse(root, val, depth-1);
    }
    
    TreeNode* traverse(TreeNode* root, int val, int depth) {
       if (!root)
            return nullptr;
        
        if (depth == 1) {
            TreeNode* l = new TreeNode(val);
            TreeNode* r = new TreeNode(val);
            
            l->left = root->left;
            r->right = root->right;
            
            root->left = l;
            root->right = r;
            return root;
        }

        root->left = traverse(root->left, val, depth-1);
        root->right = traverse(root->right, val, depth-1);
        return root;
        
    }
};