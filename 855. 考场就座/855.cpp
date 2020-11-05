class ExamRoom {
public:
    set<int> s;
    int max_num;
    ExamRoom(int N) {
        max_num = N;
    }
    
    int seat() {
        if(s.size() == 0)
        {
            s.insert(0);
            return 0;
        }
        if(s.size() == 1)
        {
            int result = (*s.begin()-0) >(max_num-1-*s.begin())?0:max_num-1;
            s.insert(result);
            return result;
        }

        auto first = s.begin();
        int result = 0;
        int record = (*first-0);
        for(int i = 1; i < s.size(); i++)
        {
            auto last = first;
            last++;
            if((*last-*first)/2 > record)
            {
                record = (*last-*first)/2;
                result = *first + record;
            }
            first++;
        }
        if((max_num-1-*first)>record)
        {
            result = max_num-1;
        }
        s.insert(result);
        return result;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */