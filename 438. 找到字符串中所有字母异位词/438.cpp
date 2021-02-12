class Solution {
public:
    bool check(int num[],int target[]){
        bool ans=true;
        for(int i=0;i<26;i++)
            if(num[i]<target[i]){
                ans=false;
                break;
            }
        return ans;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int len=p.size();
        int n=s.size();
        if(n<len) return ans;
        int left=0,right=0;
        int num[26],target[26];
        for(int i=0;i<26;i++){
            num[i]=0;
            target[i]=0;
        }
        for(auto c:p)
            target[c-'a']++;
        while(right<n){
            num[s[right]-'a']++;
            if(right-left+1==len){
                if(check(num,target)){
                    ans.push_back(left);
                }
                num[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return ans;
    }
};
