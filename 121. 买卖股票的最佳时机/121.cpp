class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int result = 0;
        int min_num = prices[0];
        for(int i = 1; i < n; i++)
        {
            if(prices[i] < min_num)
            {
                min_num = prices[i];
            }
            else
            {
                result = max(result,prices[i]-min_num);
            }
        }
        return result;
    }
};