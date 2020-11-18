class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() -1;
        int result = 0;
        while(i < j)
        {
            if((j-i)*min(height[i],height[j]) > result)
            {
                result = (j-i)*min(height[i],height[j]);
            }
            if(height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return result;
    }
};