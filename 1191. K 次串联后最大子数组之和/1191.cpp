class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // 动态规划求区间最大
        // 从左遍历，求左边部分的最大
        // 从右遍历，求右边部分的最大
        // 求整个数组和，如果小于0则记作0
        // 如果k为1，返回区间最大，如果k为2，返回max（区间最大，左边最大+右边最大的和）
        // 如果k大于2，返回max（区间最大，左边最大+右边最大+k-2倍数组和）
        int left_max = 0;
        int right_max = 0;
        int temp = 0;
        int local_max = max_between(arr);
        for(int i = 0; i < arr.size(); i++)
        {
            temp += arr[i];
            left_max = max(left_max,temp);
        }
        long sum = max(0,temp);
        temp = 0;
        for(int i = arr.size()-1; i>=0; i--)
        {
            temp += arr[i];
            right_max = max(right_max,temp);
        }

        if(k == 1) return local_max;
        else if(k == 2) return max((left_max+right_max)%1000000007,local_max);
        else return max(int(left_max+right_max+(sum*(k-2))%1000000007), local_max)%1000000007;
    }
    int max_between(vector<int>& arr)
    {
        int result = 0;
        int max_num = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            max_num = max(arr[i], max_num + arr[i]);
            result = max(result,max_num);
        }
        return result;
    }
};