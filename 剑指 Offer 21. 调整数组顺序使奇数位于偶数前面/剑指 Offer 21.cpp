class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int first = 0;
        int last = nums.size()-1;
        while(first < last){
            while(first < last && nums[first] % 2 != 0) first++;
            while(first < last && nums[last] % 2 == 0) last--;
            swap(nums[first], nums[last]);
            first++;
            last--;
        }
        return nums;
    }
};