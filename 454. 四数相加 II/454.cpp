class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        for(int numA:A)
        {
            for(int numB:B)
            {
                m[numA+numB]++;
            }
        }
        int result = 0;
        for(int numC:C)
        {
            for(int numD:D)
            {
                if(m.find(-(numC+numD)) != m.end())
                {
                    result += m[-(numC+numD)];
                }
            }
        }
        return result;
    }
};