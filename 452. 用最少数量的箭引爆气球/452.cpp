class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[&](vector<int> a, vector<int> b)
        {
            return a[0] == b[0]?a[1] < b[1]:a[0]<b[0];
        });
        int result = 0;
        int i = 0;
        while(i < points.size())
        {
            int j = i+1;
            int record = points[i][1];
            while(j < points.size())
            {
                if(points[j][0] >record)
                {
                    break;
                }
                else
                {
                    record = min(record,points[j][1]);
                }
                j++;
            }
            i = j;
            result++;
        }
        return result;
    }
};