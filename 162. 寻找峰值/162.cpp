class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int first = 0;
        int last = nums.size()-1;
        while(first < last)
        {
            int mid = (first+last)/2;
            if(nums[mid]>nums[mid+1]){
                last=mid;
            }
            else{
                first=mid+1;
            }
        }
        return first;
    }
};