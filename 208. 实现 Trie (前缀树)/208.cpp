class Trie {
public:
    // 字典树
    struct TreeNode//树的结点结构
    {
        char val;
        bool isword;
        TreeNode *next[26];//指向儿子结点
        TreeNode()//每个结点的初始化
        {
            isword = false;
            val = '.';
            for(int i=0;i<26;i++)
                next[i]=NULL;
        }
    };
    /** Initialize your data structure here. */
    TreeNode* root = new TreeNode();
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* head = root;
        for(auto ch:word)
        {
            if(head->next[int(ch-'a')] == NULL) 
            {
                head->next[int(ch-'a')] = new TreeNode();
                head = head->next[int(ch-'a')];
                head->val = ch;
                head->isword = false;
            }
            else
            {
                head = head->next[int(ch-'a')];
            }
        }
        head->isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode* head = root;
        for(auto ch:word)
        {
            if(head->next[int(ch-'a')] == NULL) return false;
            head = head->next[int(ch-'a')];
        }
        if(head->isword == true) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode* head = root;
        for(auto ch:prefix)
        {
            if(head->next[int(ch-'a')] == NULL) return false;
            head = head->next[int(ch-'a')];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */