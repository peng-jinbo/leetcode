class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int result = 0;
        inventory.push_back(0);
        sort(inventory.begin(), inventory.end());
        int count = 1;
        long temp = 0;
        long n;
        for(int i = inventory.size()-1; i > 0; i--)
        {
            if(orders >= count*(inventory[i] - inventory[i-1]))
            {
                n = inventory[i] - inventory[i-1];
                temp = (n*(n-1)/2)%1000000007;
                result = (result + count*((((inventory[i-1] + 1)*n)%1000000007 + temp)%1000000007))%1000000007;
                orders -= count*(inventory[i] - inventory[i-1]);
            }
            else
            {
                
                long num = orders/count;
                temp = num*(num-1)/2;
                result = (result + count*((((inventory[i] -num+1)*num)%1000000007 + temp)%1000000007))%1000000007;
                orders = orders%count;
                result = (result + orders*(inventory[i] -num))%1000000007;
                break;


            }
            count++;
        }
        return result;
    }
};