class RandomizedSet {
public:
    /** Initialize your data structure here. */
    map<int, int> mp;
    vector<int> v;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        mp[val] = v.size();
        v.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int idx = mp[val];
        int x = v.back();
        v[idx] = x;
        mp[x] = idx;
        mp.erase(val);
        v.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % (v.size());
        return v[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */