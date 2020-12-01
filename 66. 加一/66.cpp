class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] < 9)
        {
            digits[n-1] += 1;
            return digits;
        }
        else
        {
            int num = 1;
            digits[n-1] = 0;
            int i = n-2;
            while(i >= 0 && num > 0)
            {
                if(digits[i] + num >= 10)
                {
                    digits[i] = 0;
                    num = 1;
                }
                else{
                    digits[i] += num;
                    num = 0;
                }
                i--;
            }
            if(num == 1)
            {
                digits.insert(digits.begin(),1);
            }
            return digits;
        }
    }
};