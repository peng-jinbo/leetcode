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
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int num = q.size();
            while(num > 0)
            {
                Node* head = q.front();
                q.pop();
                num--;
                if(num != 0) head->next = q.front();
                else head->next = NULL;
                if(head->left != NULL) q.push(head->left);
                if(head->right != NULL) q.push(head->right);
            }
        }
        return root;
    }
};