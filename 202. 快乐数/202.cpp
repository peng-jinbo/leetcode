class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n!=1 && s.find(n) == s.end())
        {
            s.insert(n);
            int temp = 0;
            while(n > 0)
            {
                temp += pow(n%10,2);
                n = n / 10;
            }
            n = temp;
        }
        if(n == 1) return true;
        else return false;
    }
};