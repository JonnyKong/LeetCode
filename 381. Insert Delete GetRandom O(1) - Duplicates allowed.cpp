class RandomizedCollection {
    multiset<int> a;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = 0;
        if(a.find(val) == a.end()) result = 1;
        a.insert(val);
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(a.find(val) == a.end()) return 0;
        //Only delete one element with iterator. Otherwise all other equal nums will be deleted.
        else a.erase(a.find(val));
        return 1;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        auto p = a.begin();
        advance(p, rand() % a.size());
        return *p;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */