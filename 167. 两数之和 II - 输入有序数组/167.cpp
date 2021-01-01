class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0;
        int last = numbers.size()-1;
        vector<int> result;
        while(begin < last)
        {
            if(numbers[begin] + numbers[last] == target)
            {
                result.push_back(begin+1);
                result.push_back(last+1);
                break;
            }
            else if(numbers[begin] + numbers[last] < target) begin++;
            else last--;
        }
        return result;
    }
};