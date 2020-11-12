class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string result = "";
        for(auto num:nums)
        {
            result += to_string(num);
        }
        if(result[0] == '0') return "0";
        return result;
    }
    static bool compare(int a, int b)
    {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        return s1>s2;
    }
};