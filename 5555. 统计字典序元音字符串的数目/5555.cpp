class Solution {
public:
    int result = 0;
    char words[5] = {'a','e','i','o','u'}; 
    int countVowelStrings(int n) {
        backtrack(n,0,0);
        return result;
    }
    //回溯
    void backtrack(int n, int num, int tag)
    {
        if(num == n)
        {
            result++;
            return;
        }
        for(int i = tag; i < 5; i++)
        {
            backtrack(n,num+1,i);
        }
    }
};