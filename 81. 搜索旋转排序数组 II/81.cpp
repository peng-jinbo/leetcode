class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int begin = 0;
        while(begin < end)
        {
            int mid = (begin + end)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[begin])
            {
                begin++;
                continue;
            }
            if(nums[begin] < nums[mid])
            {
                if(nums[begin] <= target&&nums[mid] >= target)
                {
                    end = mid;
                }
                else
                {
                    begin = mid + 1;
                }
            }
            else{
                if(nums[end] >= target&&nums[mid] <= target)
                {
                    begin = mid+1;
                }
                else
                {
                    end = mid;
                }
            }
        }
        return end>=0 &&(nums[begin] == target||nums[end] == target);

    }
};