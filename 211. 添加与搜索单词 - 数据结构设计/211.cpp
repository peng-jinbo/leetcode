class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct DictTree{
        DictTree* next[26];
        bool end;
        DictTree(){
            end = false;
            for(int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };
    DictTree* root = new DictTree();
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        DictTree* head = root;
        for(char c:word)
        {
            int num = c-'a';
            if(head->next[num] == NULL) head->next[num] = new DictTree();
            head = head->next[num];
        }
        head->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool find_word(DictTree* p, string& word, int si)
    {
        if(si == word.size()) return p->end;
        if(word[si] == '.')
        {
            for(int i = 0; i < 26; i++)
                if(p->next[i] && find_word(p->next[i], word, si + 1))
                    return true;
        }
        else
        {    
            int u = word[si] - 'a';
            if(p->next[u]) return find_word(p->next[u], word, si + 1);   
            else return false;
        }
        return false;
    }

    bool search(string word) {
        return find_word(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */