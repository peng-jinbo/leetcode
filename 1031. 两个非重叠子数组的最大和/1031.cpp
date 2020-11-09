class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        // 利用前缀和
        vector<int> presum;
        int result = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(i == 0)
            {
                presum.push_back(A[i]);
            }
            else
            {
                presum.push_back(A[i]+presum[i-1]);
            }
        }
        for(int i = L-1; i < A.size(); i++)
        {
            int temp = 0;
            if(i == L-1)
            {
                temp = presum[i];
            }
            else{
                temp = presum[i]-presum[i-L];
            }
            int m_max = 0;
            for(int j = M-1; j < i-L+1; j++)
            {
                if(j == M-1)
                {
                    m_max = max(m_max,presum[j]);
                }
                else{
                    m_max = max(m_max,presum[j]-presum[j-M]);
                }
            }
            for(int k = i+M; k < A.size(); k++)
            {
                m_max = max(m_max,presum[k]-presum[k-M]);
            }
            result = max(result,temp + m_max);
        }
        return result;
    }
};