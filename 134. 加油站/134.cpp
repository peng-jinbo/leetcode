class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int sum_gas = 0;
        int sum_cost = 0;
        int sum_loss = 0;
        int result = 0;
        while(i < gas.size())
        {
            sum_cost += cost[i];
            sum_gas += gas[i];
            if(sum_gas < sum_cost)
            {
                sum_loss += (sum_cost - sum_gas);
                sum_cost = 0;
                sum_gas = 0;
                result = i+1;
            }
            i++;
        }
        if(sum_gas-sum_cost >= sum_loss)
        {
            return result;
        }
        else
        {
            return -1;
        }
    }
};