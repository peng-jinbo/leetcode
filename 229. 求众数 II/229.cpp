/*
时间复杂度为：O(n)
空间复杂度为：O(1)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        vector<int>res, cands, cnts;
        if(len == 0){//没有元素，直接返回空数组
            return res;
        }
        cands.assign(2, nums[0]);
        cnts.assign(2, 0);
        //第1阶段 成对抵销
        for(auto num: nums){
            bool flag = false;
            for(int i = 0; i < cands.size(); ++i){
                if(num == cands[i]){
                    ++cnts[i];
                    flag = true;
                    break;
                }
            }
            if(!flag){
                bool flag2 = false;
                for(int j = 0; j < cands.size(); ++j){
                    if(cnts[j] == 0){
                        flag2 = true;
                        cands[j] = num;
                        cnts[j]++;
                        break;
                    }
                }
                if(!flag2){
                    for(int j = 0; j < cnts.size(); ++j){
                        --cnts[j];
                    }
                }
            }
        }

        //第2阶段 计数 数目要超过三分之一
        cnts[0] = cnts[1] = 0;
        if(cands[0] == cands[1])
            cands.pop_back();
        for(auto num:nums){
            for(int i = 0; i < cands.size(); ++i){
                if(cands[i] == num){
                    ++cnts[i];
                    break;
                }
            }
        }
        for(int i = 0; i < cands.size(); ++i){
            if(cnts[i] > len / 3){
                res.push_back(cands[i]);
            }
        }
        return res;
    }
};