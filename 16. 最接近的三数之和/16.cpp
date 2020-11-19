class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                int temp = nums[i] + nums[left] + nums[right];
                if(temp == target)
                {
                    return temp;
                }
                else if(temp > target)
                {
                    if(abs(result - target) > abs(temp - target))
                        result = temp;
                    right--;
                }
                else{
                    if(abs(result - target) > abs(temp - target))
                        result = temp;
                    left++;
                }
            }
        }
        return result;
    }
};