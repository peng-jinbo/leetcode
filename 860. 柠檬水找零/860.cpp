class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> count(2,0);
        for(auto bill:bills)
        {
            if(bill == 5) count[0]++;
            else if(bill == 10)
            {
                if(count[0] <= 0) return false;
                else
                {
                    count[0]--;
                    count[1]++;
                }
            }
            else{
                if(count[1] >= 1&& count[0] >= 1)
                {
                    count[1]--;
                    count[0]--;
                }
                else if(count[0] >= 3) count[0] -= 3;
                else return false;
            }
        }
        return true;
    }
};