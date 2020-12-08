class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        backtrack(S,0,0,0);
        return result;
    }
    bool backtrack(string S, long long sum, int pos, int pre)
    {
        if(pos == S.length())
        {
            return result.size() >= 3;
        }
        long long curr = 0;
        for(int i = pos; i < S.length(); i++)
        {
            if(i>pos && S[pos] == '0')
            {
                return false;
            }
            curr = curr * 10 + S[i] - '0';
            if (curr > INT_MAX) {
                break;
            }
            if (result.size() >= 2) {
                if (curr < sum) {
                    continue;
                }
                else if (curr > sum) {
                    break;
                }
            }
            result.push_back(curr);
            if(backtrack(S,pre+curr,i+1,curr)) return true;
            result.pop_back();
        }
        return false;
    }
private:
    vector<int> result;    
};