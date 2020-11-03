class TopVotedCandidate {
public:
    // 首先用一个vector记录在每一个times中的时间节点票数多的人
    // 考虑用一个map来进行统计
    // 然后用二分查找判断是在哪个时间节点直接输出结果
    vector<int> result;
    vector<int> p_times;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        p_times = times;
        map<int,int> m;
        int max_num = 0;
        int max_person = 0;
        for(auto person:persons)
        {
            if(max_num == 0)
            {
                m[person] = 1;
                max_num = 1;
                max_person = person;
                result.push_back(person);
            }
            else
            {
                m[person] += 1;
                if(m[person] >= max_num)
                {
                    max_num = m[person];
                    result.push_back(person);
                    max_person = person;
                }
                else{
                    result.push_back(max_person);
                }
            }
        }
    }
    
    int q(int t) {
        int last = p_times.size();
        int first = 0;
        if(t >= p_times[last-1]) return result[last-1];
        while(first < last-1)
        {   
            int mid = (first+last)/2;
            if(p_times[mid] < t)
            {
                first = mid;
            }
            else{
                last = mid;
            }
        }
        if(p_times[last] == t) return result[last];
        else return result[first];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */