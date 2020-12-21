class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 0) return 0;
        if(n == 1) return cost[0];
        if(n == 2) return min(cost[0], cost[1]);
        int a = cost[0];
        int b = cost[1];
        for(int i = 2; i < n; i++)
        {
            int temp = a;
            a = b;
            b = min((cost[i] + temp),(cost[i]+b));
        }
        return min(a,b);
    }
};