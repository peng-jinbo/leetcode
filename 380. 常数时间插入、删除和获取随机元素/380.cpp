class RandomizedSet {
private:
    unordered_map<int,int> hash;    //哈希表储存元素值和对应下标，为了remove时实现O（1）
    vector<int> dyArray;        //vector可以作为动态数组，实现getRandom和insert的常数时间操作

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = hash.find(val);
        if(it != hash.end()) return false;  //如果集合中已经存在val，返回false，节省时间
        dyArray.push_back(val);
        hash[val] = dyArray.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = hash.find(val);
        if(it == hash.end()) return false;  //删除时，如果集合中不存在val，返回false

        int lastPos = dyArray.size() - 1;   //将被删除值和数组最后一位进行交换
        int valPos = hash[val];
        dyArray[valPos] = dyArray[lastPos];
        dyArray.pop_back();                 //vector数组删除val
        hash[dyArray[valPos]] = valPos;     //被交换的值下标发生变化，需要更新
        hash.erase(val);                    //哈希表中删除val的项
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = dyArray.size();
        int pos = rand()%size;  //对下标产生随机数
        return dyArray[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
