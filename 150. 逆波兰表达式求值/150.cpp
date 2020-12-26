class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            string token = tokens[i];
            if(token != "+" && token != "-" && token != "*" && token != "/")
            {
                s.push(stoi(token));
                continue;
            }
            int num1 = s.top();
            s.pop();
            int num2 = s.top();
            s.pop();
            if(token == "+") s.push(num1+num2);  
            else if(token == "-") s.push(num2-num1);  
            else if(token == "*") s.push(num1*num2);  
            else if(token == "/") s.push(num2/num1);    
        }
        return s.top();
    }
};