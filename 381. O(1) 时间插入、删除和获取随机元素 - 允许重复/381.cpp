class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int> stored;     //存储元素的vector
    unordered_map<int,set<int>> index_hash;  //存储每个val的所有在stored下标的哈希表
    int len = stored.size();    //记录stored的长度
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) 
    {
        //插入stored，维护哈希表，长度加1
        bool result = true;
        stored.push_back(val);
        if(index_hash.find(val) != index_hash.end()) result = false;
        index_hash[val].insert(len);
        len++;
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        // 将val对应的一个下标与stored的最后一个元素交换，并删除val对应的下标，修改最后一个元素对应的下标
        if(index_hash.find(val) == index_hash.end()) return false;
        else
        {
            int i = *(index_hash[val].begin());
            stored[i] = stored[len-1];
            index_hash[val].erase(i);
            index_hash[stored[i]].erase(len-1);
            if(i < len-1)       //要删除元素恰好是最后一个时不修改
            {
                index_hash[stored[i]].insert(i);
            }
            if(index_hash[val].size() == 0) //删除该元素最后一个时去掉键值
            {
                index_hash.erase(val);
            }
            len--;
            stored.pop_back();
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        // 随机取数
        return stored[rand() % len];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */