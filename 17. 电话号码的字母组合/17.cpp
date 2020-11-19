class Solution {
public:
    vector<string> result;
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return result;
        string temp = "";
        backtrack(digits,temp,0);
        return result;
    }
    void backtrack(string& digits, string temp, int num)
    {
        if(num >= digits.length())
        {
            result.push_back(temp);
            return;
        }
        for(char ch:phoneMap[digits[num]])
        {
            backtrack(digits,temp+ch,num+1);
        }
    }
};