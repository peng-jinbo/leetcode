class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int n = nums.size() - 1;
        int right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right)/2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid])
            {
                if(target >= nums[left] && target <= nums[mid])
                {
                    right = mid;
                }
                else{
                    left = mid+1;
                }
            }
            else
            {
                if(target <= nums[right] && target >= nums[mid])
                {
                    left = mid+1;
                }
                else{
                    right = mid;
                }
            }
        }
        return nums[left] == target?left:-1;
    
    }
};