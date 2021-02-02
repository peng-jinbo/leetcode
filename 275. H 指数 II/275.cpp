class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for(int i = n; i > 0; i--)
        {
            if(citations[n-i]>=i)
            {
                return i;
            }
        }
        return 0;
    }
};