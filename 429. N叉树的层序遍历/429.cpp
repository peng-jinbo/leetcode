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
    // 队列层序遍历
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> q;
        if(root != NULL) 
            q.push(root);
        int count = 1;
        int count_t;
        vector<int> temp;
        while(!q.empty())
        {
            while(count > 0)
            {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                count--;
                for(auto c:root->children){
                    q.push(c);
                }
            }
            result.push_back(temp);
            temp.clear();
            count = q.size();
        }
        return result;
    }
};