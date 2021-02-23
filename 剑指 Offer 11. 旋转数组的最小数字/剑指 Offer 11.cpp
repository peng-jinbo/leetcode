class Solution {
public:
    int minArray(vector<int>& numbers) {
        int begin = 0;
        int end = numbers.size()-1;
        if(numbers[begin] < numbers[end]) return numbers[begin];
        while(begin < end)
        {
            int mid = begin + (end-begin)/2;
            if(numbers[mid] > numbers[end]) begin = mid+1;
            else if(numbers[mid] < numbers[end]) end = mid;
            else end--;
        }
        return numbers[begin] < numbers[end]?numbers[begin]:numbers[end];
    }
};