class Solution {
public:
    string replaceSpace(string s) {
        string result = "";
        for(char ch:s){
            if(ch == ' '){
                result += "%20";
            }
            else result += ch;
        }
        return result;
    }
};