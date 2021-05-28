/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    Node* populate(Node *root, Node *parent) {
        if (!root)
            return NULL;
        
        if (!parent)
            root->next = NULL;
        else {
            if (root == parent->left) {
                root->next = parent->right;
            } else {
                if (parent->next == NULL)
                    root->next = NULL;
                else root->next = parent->next->left;
            }
        }
        
        root->left = populate(root->left, root);
        root->right = populate(root->right, root);
        return root;
    }
    
    Node* connect(Node* root) {
        return populate(root, NULL);
    }
};