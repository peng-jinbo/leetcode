class Solution {
public:
        int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int l = nums.size() - 1;
        int r = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        return (r > l) ? r - l + 1 : 0;
    }
};