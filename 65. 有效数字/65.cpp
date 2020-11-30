class Solution {
public:
    bool isNumber(string s) {
        int i=0;
        //跳过开头的空字符
        while(s[i]==' ')++i;
        //跳过正负号
        if(s[i]=='+'||s[i]=='-')++i;
        //匹配一个整数
        bool match1 = matchInt(s, i);
        //如果匹配到了‘.’，在匹配一个整数
        if(s[i]=='.'){
            i++;
            bool match2 = matchInt(s, i);
            //‘.’前后至少要有一个整数
            if(!match1 && !match2)return false;
        }else
            //如果没有'.'，至少应有一个整数
            if(!match1)return false;
        
        //e后面应该有一个整数
        if(s[i]=='e'){
            ++i;
            if(s[i]=='+' || s[i]=='-')++i;
            if(!matchInt(s, i))return false;
        }
        //跳过末尾的空格。
        while(s[i]==' ')++i;
        //此时字符串应该到了末尾如果没有，返回false。
        return !s[i];
        
    }

    bool matchInt(string& s, int& i){
        int start = i;
        while(s[i]>='0' && s[i]<='9')++i;
        return start!=i;
    }
};