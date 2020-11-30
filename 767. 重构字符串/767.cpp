class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char,int> u_map;
        for(char ch:S) u_map[ch] += 1;
        priority_queue<pair<int,char>> q;
        for(auto iter:u_map) q.emplace(iter.second,iter.first);
        string result = "";
        while(q.top().first!=0)
        {
            if(result != "")
            {
                if(result.back() != q.top().second)
                {
                    result += q.top().second;
                    int num = q.top().first;
                    q.pop();
                    q.emplace(num-1,result.back());
                }
                else
                {
                    int num1 = q.top().first;
                    char temp = q.top().second;
                    q.pop();
                    if(q.empty() || q.top().first == 0) return "";
                    else{
                        result += q.top().second;
                        int num = q.top().first;
                        q.pop();
                        q.emplace(num-1,result.back());
                        q.emplace(num1,temp);
                    }
                }
            }
            else{
                result += q.top().second;
                int num = q.top().first;
                q.pop();
                q.emplace(num-1,result.back());
            }
        }
        return result;

    }
};