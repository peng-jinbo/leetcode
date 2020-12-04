class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        stack<pair<int,int>> s;
        s.push(pair(-1,-1));
        vector<int> left_dp(n);
        vector<int> right_dp(n);
        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                left_dp[i] = 0;
            }
            else
            {
                if(heights[i] > heights[i-1]) left_dp[i] = 0;
                else
                {
                    while(s.top().first>=heights[i]) {s.pop();}
                    left_dp[i] = (i-s.top().second-1);
                }
            }
            s.push(pair(heights[i],i));
        }
        while(!s.empty()) s.pop();
        s.push(pair(-1,n));
        for(int i = n-1; i >= 0; i--)
        {
            if(i == n-1) right_dp[i] = 0;
            else{
                if(heights[i] > heights[i+1]) right_dp[i] = 0;
                else
                {
                    while(s.top().first>=heights[i]) {s.pop();}
                    right_dp[i] = (s.top().second-i-1);
                } 
            }
            s.push(pair(heights[i],i));
        }
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            int temp = heights[i]*(left_dp[i]+right_dp[i]+1);
            result = max(result,temp);
        }
        return result;
    }
};