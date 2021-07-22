/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) 
            return {};
        vector<vector<int>> res;
        Node *nextLevel = nullptr;
        
        queue<Node*> q;
        q.push(root);
        q.push(nextLevel);
        
        int level = 0;
        
        while(q.size() > 1) {
            Node* temp = q.front();
            q.pop();
            if (res.size() == level) 
                res.push_back({});
            
            while(temp) {
                res[level].push_back(temp->val);
                
                for (int i = 0; i < temp->children.size(); i++) {
                    q.push(temp->children[i]);
                }
                temp = q.front();
                q.pop();
            }
            q.push(nullptr);
            level++;
        }
        return res;
    }
};