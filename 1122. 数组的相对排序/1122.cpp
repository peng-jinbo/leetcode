class Solution {
public:
    // 计数排序
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(1001,0);
        for(int i = 0; i < arr1.size(); i++)
        {
            count[arr1[i]]++;
        }
        vector<int> result;
        for(int i = 0; i < arr2.size(); i++)
        {
            while(count[arr2[i]])
            {
                result.push_back(arr2[i]);
                count[arr2[i]]--;
            }
        }
        for(int i = 0; i < count.size(); i++)
        {
            while(count[i])
            {
                result.push_back(i);
                count[i]--;
            }
        }
        return result;

    }
    
};