/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res = nullptr;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root, p, q);
        return res;
    }
    
    int lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return 0;
        
        int left = lca(root->left, p, q);
        int right = lca(root->right, p, q);
        
        int d = (root->val == p->val || root->val == q->val) ? 1 : 0;
        
        if (left + right + d >= 2)
            res = root;
        
        return left + right + d >= 1 ? 1 : 0;
            
    }
};