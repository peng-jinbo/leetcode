class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> q;
    MinStack() {
    }
    
    void push(int x) {
        if(q.empty())
            q.push(pair(x,x));
        else
            q.push(pair(x,min(x,q.top().second)));
    }
    
    void pop() {
        q.pop();
    }
    
    int top() {
        return q.top().first;
    }
    
    int getMin() {
        return q.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */