class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1,-1};
        if(nums.size() == 0) return result;
        int left = 0;
        int right = nums.size()-1;
        while(left<right)
        {
            int mid = (left + right)/2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        if(nums[left] != target) return result;
        result[0] = left;
        left = 0;
        right = nums.size()-1;;
        while(left<right)
        {
            int mid = (left + right)/2;
            if(nums[mid] <= target)
            {
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        result[1] = nums[left] == target?left:left-1;
        return result;
        
    }
};