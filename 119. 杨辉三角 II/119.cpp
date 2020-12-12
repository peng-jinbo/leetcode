class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,0);
        for(int i = 0; i <= rowIndex; i++)
        {
            int temp = 1;
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i) result[j] = 1;
                else if(j <= i/2)
                {
                    int temp1 = result[j];
                    result[j] = temp + result[j];
                    temp = temp1;
                }
                else{
                    result[j] = result[i-j];
                }
            }
        }
        return result;
    }
};