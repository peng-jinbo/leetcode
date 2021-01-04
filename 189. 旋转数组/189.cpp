class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int begin = 0;
        int end = nums.size()-1;
        k = k%(end+1);
        int mid = end - k;
        while(begin < mid)
        {
            swap(nums[begin],nums[mid]);
            begin++;
            mid--;
        }
        mid = end-k+1;
        while(mid<end)
        {
            swap(nums[mid],nums[end]);
            mid++;
            end--;
        }
        begin = 0;
        end = nums.size()-1;
        while(begin < end)
        {
            swap(nums[begin],nums[end]);
            begin++;
            end--;
        }
    }
};