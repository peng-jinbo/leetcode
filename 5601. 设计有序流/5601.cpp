class OrderedStream {
public:
    map<int,string> m;
    int pos = 1;
    int max_num;
    OrderedStream(int n) {
        max_num = n;
    }
    
    vector<string> insert(int id, string value) {
        vector<string> result;
        m[id] = value;
        while(m.find(pos) != m.end())
        {
            result.push_back(m[pos]);
            pos++;
        }
        return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */