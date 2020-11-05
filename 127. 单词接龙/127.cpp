class Solution {
public:
    // 广度优先搜索，注意两点，第一点判断两个单词的编辑距离不要用函数，第二点遍历过的点可以在图中删除
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,set<string>> m;
        wordList.push_back(beginWord);
        auto n = size(beginWord);
        for (auto&& a : wordList) {
            for (auto&& b : wordList) {
                if ( [&] {
                    size_t cnt = 0;
                    for (int i = 0; i != n; ++i) {
                        if (a[i] != b[i]) {
                            ++cnt;
                            if (cnt == 2) return false;
                        }
                    }
                    return cnt == 1;
                }() )
                {
                    m[a].insert(b);
                    m[b].insert(a);
                }
            }
        }
        int result = 0;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty())
        {
            result++;
            int n = q.size();
            for(int i = 0; i< n; i++)
            {
                string cur = q.front();
                q.pop();
                if(cur == endWord) return result;
                for(auto&& word:m[cur])
                {
                    m[word].erase(cur);
                    q.push(word);
                }
                m[cur].clear();
            }
        }
        return 0;
    }
};