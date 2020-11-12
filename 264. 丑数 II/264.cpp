class Solution {
public:
    int nthUglyNumber(int n) {
        // 三个指针
        int a = 0;
        int b = 0;
        int c = 0;
        vector<int> dp;
        dp.push_back(1);
        if(n == 1) return 1;
        n--;
        int min_num;
        while(n)
        {
            min_num = min(dp[b]*3,dp[a]*2);
            min_num = min(min_num,dp[c]*5);
            if(min_num%2==0) a++;
            if(min_num%3==0) b++;
            if(min_num%5==0) c++;
            dp.push_back(min_num);
            n--;
        }
        return min_num;
    }
};