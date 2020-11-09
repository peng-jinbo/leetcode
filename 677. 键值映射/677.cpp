class MapSum {
public:
    /** Initialize your data structure here. */
    // 字典树
    struct Node{
        int value;
        vector<Node*> children;
        Node()
        {
            value = 0;
            for(int i = 0; i < 26; i++)
            {
                children.push_back(NULL);
            }
        }
    };
    unordered_map<string, int> m;
    Node* root = new Node();
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        bool tag = (m.find(key) == m.end());
        Node* head = root;
        for(char ch:key)
        {
            if(head->children[int(ch-'a')] == NULL)
            {
                head->children[int(ch-'a')] = new Node();
            }
            head = head->children[int(ch-'a')];
            if(tag)
            {
                head->value += val;
            }
            else
            {
                head->value = head->value - m[key] + val;
            }
        }

        m[key] = val;
    }
    
    int sum(string prefix) {
        Node* head = root;
        for(char ch:prefix)
        {   
            if(head == NULL) return 0;
            head = head->children[int(ch-'a')];
        }
        if(head == NULL) return 0;
        return head->value;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */