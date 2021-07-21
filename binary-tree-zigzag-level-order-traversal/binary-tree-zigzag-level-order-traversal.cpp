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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       if (!root)
           return {};
        
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode * newLevel = nullptr;
        q.push(newLevel);
        int level = 0;
        
        while (q.size() > 1) {
            res.push_back({});
            TreeNode *temp = q.front();
            q.pop();
            
            while (temp) {
                res[level].push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                temp = q.front();
                q.pop();
            }
            q.push(temp);
            if (level%2)
                reverse(res[level].begin(), res[level].end());
            
            level++;
        }
        
        return res;
        
    }
};