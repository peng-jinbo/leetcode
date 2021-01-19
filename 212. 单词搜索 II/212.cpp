// 字典树
class TrieNode {
private:

   TrieNode* next[26];     // 孩子列表[0-25]表示['a'-'z']，nullptr表示无
   TrieNode* parent;       // 该结点的父结点/双亲结点
   char flag;              // 控制标记。-1 逻辑已删除； 0：作为中间链路；1：有效单词结束
   int numsOfNext;         // 当前结点的孩子个数，叶结点为0

public:
   // 构造函数
   // param: [bool] isRoot - 初始化的根结点需要置true
   TrieNode(bool isRoot = false) {
       for (int i = 0; i < 26; ++i) next[i] = nullptr;
       flag = isRoot;
       parent = nullptr;
       numsOfNext = 0;
   }

   // 在字典树的根结点插入单词记录 (若存在则跳过，默认在单词结尾的字符结点置其控制标记flag为1)
   // param: [TrieNode*] root - 一般传字典树根结点
   // param: [string] word - 单词
   // return: [TrieNode*] - 返回插入的单词末尾字符结点
   static TrieNode* insert(TrieNode* root, string word) {
       auto ptr = root;
       for (char c : word) {
           if (ptr->next[c-'a'] == nullptr) {
               ptr->next[c-'a'] = new TrieNode();
               ptr->next[c-'a']->parent = ptr;
               ++ptr->numsOfNext;
           }
           ptr = ptr->next[c-'a'];
       }
       ptr->flag = true;
       return ptr;
   }

   // 在字典树的某个结点插入下一个字符结点 (若存在则跳过，需要指定其是否是单词结尾)
   // param: [TrieNode*] root - 字典树的某个结点
   // param: [char] c - 字符
   // param: [bool] isEnd - 是否以此为结尾够成新单词
   // return: [TrieNode*] - 返回插入的新字符结点
   static TrieNode* insert(TrieNode* root, char c, bool isEnd) {
       if (root->next[c-'a'] == nullptr) {
           root->next[c-'a'] = new TrieNode();
           root->next[c-'a']->parent = root;
           ++root->numsOfNext;
       }
       root->next[c-'a']->flag = isEnd;
       return root->next[c-'a'];
   }

   // 在字典树的根个结点查找单词记录 (需满足单词结尾的字符结点其控制标记flag为1)
   // param: [TrieNode*] root - 一般传字典树根结点
   // param: [string] word - 单词
   // return: [bool] - 是否存在
   static bool has(TrieNode* root, string word) {
       if (!root) return false;
       auto ptr = root;
       for (char c : word) {
           if (ptr->next[c-'a'] == nullptr || ptr->next[c-'a']->flag == -1) {
               return false;
           }
           ptr = ptr->next[c-'a'];
       }
       return ptr->flag == 1;
   }

   // 在字典树的某结点查找是否存在下一个指定的字符
   // param: [TrieNode*] root - 字典树的某结点
   // param: [char] c - 查找的字符
   // return: [bool] - 是否存在
   static bool has(TrieNode* root, char c) {
       if (!root) return false;
       if (root->next[c-'a'] == nullptr || root->next[c-'a']->flag == -1) {
           return false;
       }
       return true;
   }   

   // 逻辑上删除(flag置-1)，在字典树的某子结点开始向上追溯父结点/双亲结点并删除，若父结点/双亲结点有其他分叉或其flag为1(作为单词结尾)则停止删除
   // param: [TrieNode*] root - 字典树的某结点
   // return: [TrieNode*] - 返回停止删除的父结点
   static TrieNode* del_up_logicly(TrieNode* root) {
       auto cur = root;
       do {
           cur->flag = -1;
           cur = cur->parent;
           --cur->numsOfNext;

       } while (cur->flag <= 0 && cur->numsOfNext == 0);
       return cur;
   }

   //=========================================================
   // setter & getter 不做详细注释

   // 返回当前结点的下一个指定字符结点
   static TrieNode* getNextNode(TrieNode* root, char c) {
       return root->next[c-'a'];
   }

   // 返回当前结点的父结点/双亲结点
   static TrieNode* getParentNode(TrieNode* root) {
       return root->parent;
   }   

   // 返回当前结点是否是单词结尾
   static bool isEnd(TrieNode* root) {
       return root->flag == 1;
   }   

   // 返回当前结点的分支next数量
   static int getNumsOfNext(TrieNode* root) {
       return root->numsOfNext;
   }   

   // 设置当前结点是否是单词结尾
   static void setEnd(TrieNode* root, bool isEnd) {
       root->flag = isEnd;
   }   
};

// 字典树方法
class Solution {
public:
   
   int R, C;           // 最大行列值
   TrieNode* trie;     // 字典树根结点
   vector<string> ans; // 答案数组
   int need;           // 还需要多少答案数量

   vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       R = board.size();
       C = board[0].size();

       need = words.size();        // 设置答案需求数量
       
       trie = new TrieNode(true);  // 创建字典树根节点

       // 创建需要单词的字典树
       for (string& word : words) {
           trie->insert(trie, word);
       }
       
       // DFS回溯搜索
       string temp;
       for (int row = 0; row < R; ++row) {
           for (int col = 0; col < C; ++col) {
               DFS(board, row, col, 0, trie, temp);
           }
       }

       return ans;
   }

   // 深度回溯字符矩阵
   // 试探回溯字符是否够成答案需要的单词
   // param: [int] depth - 递归/回溯/DFS 深度，因为单词长度最多10，因此我们只需要递归深度到10即可返回
   // param: [TrieNode*] curNode - 当前字典树字符结点，初始化传入根结点
   // param: [string&] word - 回溯单词，临时存储当前组成的单词
   void DFS(vector<vector<char>>& board, int row, int col, int depth, TrieNode* curNode, string& word) {

       // DFS深度10
       if (depth >= 10) return;

       // 不需要再寻找了，因为答案已经找完了
       if (need == 0) return;

       // 坐标超出范围
       if (row < 0 || row >= R || col < 0 || col >= C) return;

       // 已被访问过(标记过)
       if (board[row][col] < 'a') return;

       // 在字典树中，要么该字符结点已被删除，或者没有/不存在
       if (!trie->has(curNode, board[row][col])) return;

       // 当前能够构成的单词
       word += board[row][col];

       // 取出下一个字符结点
       curNode = trie->getNextNode(curNode, board[row][col]);

       // 如果这个字符结点可以组成单词的话
       if (trie->isEnd(curNode)) {
           // 修改当前字符结点不能组成单词
           trie->setEnd(curNode, false);
           // 加入答案数组
           ans.push_back(word);
           // 减少需求数量
           --need;
           if (!need) return;

           // 如果该字符节点为叶结点
           if (trie->getNumsOfNext(curNode) == 0) {
               // 逻辑地向上回溯删除该分叉
               trie->del_up_logicly(curNode);
               // 回溯// 回溯单词
               word.pop_back();
               return;
           }
       }

       // 标记访问
       board[row][col] -= 26;
   
       DFS(board, row+1, col, depth+1, curNode, word);
       DFS(board, row-1, col, depth+1, curNode, word);
       DFS(board, row, col+1, depth+1, curNode, word);
       DFS(board, row, col-1, depth+1, curNode, word);

       // 回溯单词
       word.pop_back();
       // 回溯标记/访问
       board[row][col] += 26;
       return;
   }

};

