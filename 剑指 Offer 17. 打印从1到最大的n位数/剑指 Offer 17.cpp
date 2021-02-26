class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        for(int i = 1; log10(i) < n; i++) result.push_back(i);
        return result;
    }
};