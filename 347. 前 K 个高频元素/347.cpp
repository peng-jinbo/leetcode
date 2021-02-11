class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) m[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(auto &[num, count] : m)
        {
            if(q.size() < k) q.push(pair(count,num));
            else{
                if(count > q.top().first){
                    q.pop();
                    q.push(pair(count, num));
                }
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};