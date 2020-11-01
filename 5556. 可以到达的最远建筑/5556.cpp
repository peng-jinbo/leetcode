class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        //最小堆，先将梯子用完，然后再用砖块取代最小堆中的最小的数的梯子
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 1; i < heights.size(); i++)
        {
            int val = heights[i]-heights[i-1];
            if(val > 0)
            {
                if(q.size() < ladders)
                {
                    q.push(val);
                }
                else
                {
                    q.push(val);
                    bricks -= q.top();
                    q.pop();
                    if(bricks<0) return i-1;
                }
            }
        }
        return heights.size()-1;
    }
};