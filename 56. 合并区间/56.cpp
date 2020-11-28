class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(),[&](vector<int> a, vector<int> b)
        {
            if(a[0] == b[0]) return a[1] < b[1];
            else return a[0]<b[0];
        });
        vector<vector<int>> result;
        int pos = 1;
        int min_num = intervals[0][0];
        int max_num = intervals[0][1];
        while(pos < intervals.size())
        {
            if(intervals[pos][0] <= max_num)
            {
                max_num = max(max_num,intervals[pos][1]);
            }
            else
            {
                result.push_back({min_num,max_num});
                min_num = intervals[pos][0];
                max_num = intervals[pos][1];
            }
            pos++;
        }
        result.push_back({min_num,max_num});
        return result;
    }
};