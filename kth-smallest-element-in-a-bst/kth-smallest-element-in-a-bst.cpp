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
    stack<TreeNode*> st;
    
    int kthSmallest(TreeNode* root, int k) {
    
        if (!root)
            return 0;
        
        while(root) {
            st.push(root);
            root = root->left;
        }
        int ans = 0;
        while(k--) {
            ans = getNextValue();
        }
        return ans;
    }
    
    int getNextValue() {
        TreeNode *temp = st.top();
        st.pop();
        
        int res = temp->val;
        
        temp = temp->right;
        
        while (temp) {
            st.push(temp);
            temp = temp->left;
        }
        return res;
    }
};