class Solution {
public:
    // 构建和primes的大小一样多的指针，让新产生的丑数用db保存并利用下标找出最小
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(),0);
        vector<int> dp;
        dp.push_back(1);
        if(n == 1) return 1;
        n--;
        while(n)
        {
            int min_num = primes[0] * dp[index[0]];
            for(int i = 1; i < primes.size(); i++)
            {
                min_num = min(min_num, primes[i] * dp[index[i]]);
            }
            for(int i = 0; i < primes.size(); i++)
            {
                if(min_num % primes[i] == 0)
                {
                    index[i]++;
                }
            }
            dp.push_back(min_num);
            n--;
        }
        return dp.back();
    }
};