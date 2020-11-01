class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // 记录pieces的每一个子vector的头的位置
        vector<int> stored(101,0);
        int n = pieces.size();
        if(n == 0) return false;
        for(int i = 0; i < n; i++)
        {
            stored[pieces[i][0]] = i;
        }
        int j = 0;
        // 判断
        while(j < arr.size())
        {
            int col = stored[arr[j]];
            for(auto num:pieces[col])
            {
                if(arr[j] == num) j++;
                else return false;
            }
        }
        return true;
    }
};