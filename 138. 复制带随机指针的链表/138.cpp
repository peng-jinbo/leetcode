/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        mp[nullptr]=nullptr;
        auto p=head;
        while(p){
            mp[p]=new Node(p->val);
            p=p->next;
        }
        p=head;
        while(p){
            mp[p]->next=mp[p->next];
            p=p->next;
        }
        p=head;
        while(p){
            mp[p]->random=mp[p->random];
            p=p->next;
        }
        return mp[head];
    }
};
