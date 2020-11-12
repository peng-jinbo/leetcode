class Solution {
public:
    // 双指针
    vector<int> sortArrayByParityII(vector<int>& A) {

        int even = 0;
        int odd = 1;
        while(odd < A.size())
        {
            if(A[odd] % 2 == 0)
            {
                while(even < A.size() && A[even] % 2 == 0)
                {
                    even += 2;
                }
                swap(A[odd],A[even]);
            }
            odd += 2;
        }
        return A;
    }
};