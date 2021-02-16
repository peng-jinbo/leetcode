class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(int num:nums1){
            m[num]++;
        }
        vector<int> result;
        for(int num:nums2){
            if(m[num] > 0){
                result.push_back(num);
                m[num]--;
            }
        }
        return result;
    }
};