class Solution {
public:
        int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) {
            return points.size();
        }
        int res = 0;
        for (auto iterP=points.begin(); iterP!=points.end(); ++iterP) {
            unordered_map<long double, int> slope2num;
            int dup = 0, one_round_res = 0; ////< @note 每一轮内层循环都是独立的，所以要单独定义one_round_res
            for (auto iterQ=iterP+1; iterQ!=points.end(); ++iterQ) {
                if ((*iterQ)[1]==(*iterP)[1] && (*iterQ)[0]==(*iterP)[0]) { ////< @note 若两点相同
                    ++dup;
                } else if ((*iterQ)[0]==(*iterP)[0]) {  ////< @note 斜率不存在的点
                    if (slope2num.find(FLT_MAX) == slope2num.end()) {
                        slope2num[FLT_MAX] += 2;
                    } else {
                        ++slope2num[FLT_MAX];
                    }
                    one_round_res = std::max(one_round_res, slope2num[FLT_MAX]);
                } else {
                    int dy = (*iterQ)[1] - (*iterP)[1];
                    int dx = (*iterQ)[0] - (*iterP)[0];
                    long double slope = static_cast<long double>(dy) / dx;
                    if (slope2num.find(slope) == slope2num.end()) {
                        slope2num[slope] += 2;
                    } else {
                        ++slope2num[slope];
                    }
                    one_round_res = std::max(one_round_res, slope2num[slope]);
                }
            }
            if (one_round_res == 0) { ////< @note 这一轮循环全都是相同的点
                res = std::max(res, dup+1);
            } else {    ////< @note 前面判断slope还不在map中时会加2，若不区分res是否为0，会引入1个重复
                res = std::max(res, one_round_res+dup);
            }
        }
        return res;
    }
};
